#!/usr/bin/env python3
# license removed for brevity
import rospy
from sensor_msgs.msg import PointCloud
from geometry_msgs.msg import Point32
from math import sin,cos,pi

def publish_sphere_pointcloud():
    rospy.init_node('sphere_publisher', anonymous=True)
    pub = rospy.Publisher('sphere_pointcloud', PointCloud, queue_size=10)
    rate = rospy.Rate(10)  # 10Hz publishing rate
    while not rospy.is_shutdown():

        sphere_msg = PointCloud()
        sphere_msg.header.stamp = rospy.Time.now()
        sphere_msg.header.frame_id = "base_link"  # Replace 'base_link' with your desired frame ID
        # Add points to represent the circle (Here, a simple circle in the XY plane is generated)
        sphere_radius = 1.0
        num_points=100
        angle=[]
        i=0
        gap=2.0 * pi / num_points
        while not (i>(2*pi)):
            angle.append(i)
            i+=gap


        theta_lis = angle
        alpha_lis = angle

        for theta in theta_lis:
            for alpha in alpha_lis:
                point = Point32()
                point.x = sphere_radius * cos(theta) * cos(alpha)
                point.y = sphere_radius * cos(theta) * sin(alpha)
                point.z = sphere_radius * sin(theta)  
                sphere_msg.points.append(point)

        pub.publish(sphere_msg)
        rate.sleep()


if __name__ == '__main__':
    try:
        publish_sphere_pointcloud()
    except rospy.ROSInterruptException:
        pass