#!/usr/bin/env python3

import rospy
import cv2

from sensor_msgs.msg import Image,CompressedImage
from cv_bridge import CvBridge

class IMGP:
    def __init__(self) -> None:
        rospy.init_node('camera',anonymous=True)
        self.bridge=CvBridge()

        self.img_subs=rospy.Subscriber("/image_jpeg/compressed",CompressedImage,callback=self.callback)
        # node name select topic-type!
        rospy.spin()

    def callback(self,data):
        comp_img=self.bridge.compressed_imgmsg_to_cv2(data)
        cv2.imshow("Image_window",comp_img)
        cv2.waitKey(1)


if __name__ == '__main__':
    try:
        image_paraser=IMGP()
    except rospy.ROSInterruptException:
        pass
