; Auto-generated. Do not edit!


(cl:in-package kw_msgs-msg)


;//! \htmlinclude CarrotGoal.msg.html

(cl:defclass <CarrotGoal> (roslisp-msg-protocol:ros-message)
  ((func
    :reader func
    :initarg :func
    :type cl:fixnum
    :initform 0)
   (path
    :reader path
    :initarg :path
    :type cl:fixnum
    :initform 0))
)

(cl:defclass CarrotGoal (<CarrotGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CarrotGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CarrotGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kw_msgs-msg:<CarrotGoal> is deprecated: use kw_msgs-msg:CarrotGoal instead.")))

(cl:ensure-generic-function 'func-val :lambda-list '(m))
(cl:defmethod func-val ((m <CarrotGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kw_msgs-msg:func-val is deprecated.  Use kw_msgs-msg:func instead.")
  (func m))

(cl:ensure-generic-function 'path-val :lambda-list '(m))
(cl:defmethod path-val ((m <CarrotGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kw_msgs-msg:path-val is deprecated.  Use kw_msgs-msg:path instead.")
  (path m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<CarrotGoal>)))
    "Constants for message type '<CarrotGoal>"
  '((:SAVE_WAYPOINT . 0)
    (:FOLLOW_WAYPOINT . 1)
    (:PATH_ONE . 1)
    (:PATH_TWO . 2)
    (:PATH_THREE . 3))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'CarrotGoal)))
    "Constants for message type 'CarrotGoal"
  '((:SAVE_WAYPOINT . 0)
    (:FOLLOW_WAYPOINT . 1)
    (:PATH_ONE . 1)
    (:PATH_TWO . 2)
    (:PATH_THREE . 3))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CarrotGoal>) ostream)
  "Serializes a message object of type '<CarrotGoal>"
  (cl:let* ((signed (cl:slot-value msg 'func)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'path)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CarrotGoal>) istream)
  "Deserializes a message object of type '<CarrotGoal>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'func) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'path) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CarrotGoal>)))
  "Returns string type for a message object of type '<CarrotGoal>"
  "kw_msgs/CarrotGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CarrotGoal)))
  "Returns string type for a message object of type 'CarrotGoal"
  "kw_msgs/CarrotGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CarrotGoal>)))
  "Returns md5sum for a message object of type '<CarrotGoal>"
  "863fc84fc39f4df288540e2439ded070")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CarrotGoal)))
  "Returns md5sum for a message object of type 'CarrotGoal"
  "863fc84fc39f4df288540e2439ded070")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CarrotGoal>)))
  "Returns full string definition for message of type '<CarrotGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# function~%int8 SAVE_WAYPOINT = 0~%int8 FOLLOW_WAYPOINT = 1~%~%# pth num~%int8 PATH_ONE = 1~%int8 PATH_TWO = 2~%int8 PATH_THREE = 3~%~%# action filed~%# Dfine the goal~%int8 func~%int8 path~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CarrotGoal)))
  "Returns full string definition for message of type 'CarrotGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# function~%int8 SAVE_WAYPOINT = 0~%int8 FOLLOW_WAYPOINT = 1~%~%# pth num~%int8 PATH_ONE = 1~%int8 PATH_TWO = 2~%int8 PATH_THREE = 3~%~%# action filed~%# Dfine the goal~%int8 func~%int8 path~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CarrotGoal>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CarrotGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'CarrotGoal
    (cl:cons ':func (func msg))
    (cl:cons ':path (path msg))
))
