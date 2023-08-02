#!/usr/bin/env python3
# license removed for brevity

import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs import Twist

import numpy as np
import math

class WallFallowing:
    def __init__(self) -> None:
        rospy.init_node('node',anonymous=True)
        self.cmd_pub=rospy.Publisher("/cmd_val",Twist,queue_size=10)
        self.scan_sub = rospy.Subscriber('/limo/scan', LaserScan, self.laser_cb)
        self.a=0.0
        self.b=0.0
        self.error_i=0.0

    def publishCmd(self):
        control=0.0
        cmd=Twist()

        cmd.linear.x=0.3
        cmd.angular.z=0
        control+=self.slope_p()
        control+=self.dQistanceI()

        if control>1:
            cmd.linear.x=0.1
            cmd.angular.z=0.6
        elif control<-1.0:
            cmd.linear.x=0.1
            cmd.angular.z=0.6
        else:
            cmd.linear.x=0.3-control*0.24
            cmd.angular.z=control*0.6
        
        self.cmd_pub.publish(cmd)

    def laser_cb(self,scan):
        x_tmp=0.0
        y_tmp=0.0
        angle_tmp=0.0

        x_vec=[]
        y_vec=[]
        for i in range(len(scan.ranges)):
            if scan.ranges[i] != float('inf'):
                angle_tmp = scan.angle_min + i * scan.angle_increment
                x_tmp = scan.ranges[i] * math.cos(angle_tmp)
                y_tmp = scan.ranges[i] * math.sin(angle_tmp)
                
                if y_tmp > 0 and -0.3 < x_tmp < 0.3:
                    x_vec.append(x_tmp)
                    y_vec.append(y_tmp)     

        x=np.array(x_vec)   
        y=np.array(y_vec)   
        unit=np.ones_like(x)
        A = np.column_stack((x, unit))

        ans=np.linalg.lstsq(A,y,rcond=None)[0]
        self.a=ans[0]
        self.b=ans[1]

        rospy.loginfo("inclination : {}, y-intercept : {}".format(self.a, self.b))


    def slope_p(self):
        P_control = 0.0
        Kp = 5.0
        
        if -0.01 < self.a < 0.01:
            self.a = 0.0
        
        error = self.a
        P_control = Kp * error
        return P_control
    
    def dQistanceI(self):
        I_control = 0.0
        Ki = 0.1
        object_distance = 1.0
        
        error = -(object_distance - self.b)
        self.error_i += error
        self.error_i = max(min(self.error_i, 10), -10)
        
        I_control = Ki * self.error_i
        return I_control


if __name__ == '__main__':
    try:
        rospy.init_node('wall_following')
        r = rospy.Rate(10)
        wf = WallFallowing()

        while not rospy.is_shutdown():
            wf.publishCmd()
            r.sleep()
    except:
        pass