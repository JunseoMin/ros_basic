/*
this is algorithm that follow the left side of the wall
and to get the left side wall with y=ax+b this code use lest square algorithm
and to follow the wall, this code use PI control
P control with the inclination
I control with the distance to the wall 
*/

/*ROS Libraries include*/
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"

/*cpp libraries include*/
#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

/*for the linear algebra*/
#include <Eigen/Dense>

using namespace std;

class WallFollowing
{
public:
    WallFollowing() /*class initialize*/
    {
        this->cmd_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 10); /*publisher setting*/
        this->scan_sub_ = nh_.subscribe("/limo/scan", 10, &WallFollowing::laserCB, this);/*subscriber setting*/
    }

    /*method for publishing cmd_vel*/
    void publishCmd(void)
    {
        float control;
        geometry_msgs::Twist cmd;

        cmd.linear.x = 0.3;
        cmd.angular.z = 0;
        control += this->slopeP();
        control += this->distanceI();

        if(control> 1)
        {
            cmd.linear.x=0.1;
            cmd.angular.z=0.6;
        }
        else if(control<-1.0)
        {
            cmd.linear.x=0.1;
            cmd.angular.z=-0.6;
        }
        else
        {
            cmd.linear.x=0.3-control*0.24;
            cmd.angular.z=control*0.6;
        }
        
        cmd_pub_.publish(cmd);
    }


private:
    /*Node Handler and publisher and subscriber*/
    ros::NodeHandle nh_;
    ros::Publisher cmd_pub_;
    ros::Subscriber scan_sub_;

    /*y=ax+b, thinking b as distance to wall*/
    float a, b;

    // for the PI control i error
    float error_i_ =0;

    /*callback function for the lidar*/
    void laserCB(const sensor_msgs::LaserScanConstPtr & scan)
    {
        float x_temp, y_temp; //variable for the temp cartesian coordinates
        float angle_temp; // variable for the temp angle

        /*this is kind of list in c++, this will contain the lidar's x_value, y_value*/
        vector<float> x_vec, y_vec;

        /*
        this is kind of numpy in c++,
        this will contatin the lidar's x_value, y_value, 
        for the linear algebra calculation
        y1 = ax1 + b 
        y2 = ax2 + b
        y3 = ax3 + b
        ...
        (Y) = (X , 1)(a, b)^(T)
        y = A(a, b)^(T)
        1 is expressed as unit
        */
        Eigen::VectorXf x; /*vector which the size is dynamic*/
        Eigen::VectorXf y; /*vector which the size is dynamic*/
        Eigen::VectorXf unit; /*vector which the size is dynamic*/
        Eigen::MatrixXf A; /*matrix which the size is dynamic*/
        Eigen::Matrix2f temp; /*2x2 matrix*/

        /*get the every ranges list variable*/
        for(int i=0; i<scan->ranges.size(); i++)
        {
            /*if there is variable for  the scan msg*/
            if(scan->ranges[i]!=INFINITY)
            {
                /* calculate the angle*/
                angle_temp = scan->angle_min + i*scan->angle_increment;
                
                /*calculate the position in cartesian coordinates*/
                x_temp = scan->ranges[i] * cos(angle_temp);
                y_temp = scan->ranges[i] * sin(angle_temp);

                /*get the only left and +- 0.3m value and save to the vector*/
                if(y_temp > 0 && (x_temp>-0.3 && x_temp < 0.3))
                {
                    x_vec.push_back(x_temp);
                    y_vec.push_back(y_temp);
                }
            }
        }

        /*change the list value to Eigen vector to calculate least square*/
        x = Eigen::VectorXf(x_vec.size()); // make vector size to the number of x
        y = Eigen::VectorXf(y_vec.size());
        unit = Eigen::VectorXf(x_vec.size());

        for(int i =0; i<x_vec.size(); i++)
        {
            x[i] = x_vec[i];
            y[i] = y_vec[i];
            unit[i] = 1.0;
        }

        // make the matrix size to the number of x ,2 which it will be like (n) * 2
        A=Eigen::MatrixXf(x_vec.size(), 2); 

        /* make the matrix's first colum as x, and second colum as 1
        this matix will be like this
        x1 , 1
        x2 , 1
        x3 , 1
        ...
        */
        A.col(0)<<x;
        A.col(1)<<unit;

        /*psudo inverse how to inverse matrix whis is not square matrix
        A^(-1) = (A^(T) * A)^(-1) * A^(T)
        as for the equation
        A^(-1) * Y = (a, b)^(T)
        */
        temp = A.transpose()*A;
        Eigen::Vector2f answer = temp.inverse()*A.transpose()*y;

        this->a=answer[0];
        this->b=answer[1];
        cout<<"inclination : " << this->a << " , y-intercept : " << this->b << endl;
    }

    /*p control for the slope*/
    float slopeP(void)
    {
        float Pcontrol;
        float Kp = 5;
        float objectSlop = 0;
        float error;

        if(this->a <0.01 && this->a > -0.01)
            this->a=0;
        
        error = this->a;

        Pcontrol = Kp*error;
        return Pcontrol;
    }
    /*i control for the distance*/
    float distanceI(void)
    {
        float Icontrol;
        float Ki = 0.1;
        float error;
        float object_distance = 1; //object distnace 1m to the left wall  

        error = -(object_distance - this->b);
        this->error_i_ += error;
        if(this->error_i_>10)
            this->error_i_=10;
        else if(this->error_i_ < -10)
            this->error_i_=-10;
        
        Icontrol = Ki*this->error_i_;
        return Icontrol;
    }

};

int main(int argc, char ** argv)
{
    /*node initialize*/
    ros::init(argc, argv, "wall_following");
    
    /*set the publishing rate to 10hz*/
    ros::Time::init();
    ros::Rate r(10);

    /*class instance make*/
    WallFollowing wf;

    while(ros::ok())
    {
        wf.publishCmd();
        r.sleep();
        ros::spinOnce();
    }
    return 0;
}