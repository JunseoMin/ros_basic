#!/usr/bin/env python3

import rospy
import cv2
from cv_bridge import CvBridge
from sensor_msgs.msg import Image,CompressedImage

import numpy as np


class IMGparser:
    def __init__(self) -> None:
        rospy.init_node('camera',anonymous=True)
        self.bridge=CvBridge()
        self.image_subs=rospy.Subscriber('/image_jpeg/compressed',CompressedImage,self.callback)    #subs node need callback function
        self.rgb_pub=rospy.Publisher('/camera_rgb_image', Image, queue_size=10)
        self.gray_pub=rospy.Publisher('/camera_gray_img', Image, queue_size=10)
        rospy.spin()
    
    def callback(self,data):
        img_bgr = self.bridge.compressed_imgmsg_to_cv2(data)
        
        gray_img_msg = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2GRAY )
 
        rgb_img_msg=self.bridge.cv2_to_imgmsg(img_bgr,'bgr8')
        gray_img_msg=self.bridge.cv2_to_imgmsg(gray_img_msg)
        
        self.rgb_pub.publish(rgb_img_msg)       #Publisher(<node type>).publish(<message type>)
        self.gray_pub.publish(gray_img_msg)     

if __name__=='__main__':
    try:
        image_parser=IMGparser()
        
    except rospy.ROSInterruptException:
        pass