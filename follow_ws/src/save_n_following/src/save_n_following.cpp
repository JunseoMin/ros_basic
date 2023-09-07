/*ros basics*/
#include "ros/ros.h"
#include <ros/package.h>

/*to get the data of map to base link*/
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/TransformStamped.h"

/*cpp basics*/
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

/*for publishing goal*/
#include "move_base_msgs/MoveBaseAction.h"
#include "move_base_msgs/MoveBaseGoal.h"
#include "actionlib/client/simple_action_client.h"
#include "geometry_msgs/Pose.h"

/*for the  path*/
#include "nav_msgs/Path.h"
#include "geometry_msgs/PoseStamped.h"


#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <actionlib/server/simple_action_server.h>
#include <kw_msgs/CarrotAction.h>

using namespace std;

class SaveFallow
{
public:
    SaveFallow(const string &file)
    :() // 생성자가 생성되기 전 선언하는 변수
    {
        default_dir_ = file;
        current_pose_sub_=nh_.subscribe("amcl_pose",10,&SaveFallow::current_pose_CB,this);
    }

private:
    ros::NodeHandle nh_;
    string default_dir_;
    ros::Subscriber current_pose_sub_;
    
    geometry_msgs::Pose cur_pose_;

    void current_pose_CB(const geometry_msgs::PoseWithCovarianceStampedConstPtr & currentpose)
    {
        cur_pose_ = currentpose -> pose.pose;
    }
};

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "/*node_name*/");
    ros::NodeHandle nh;
    
}