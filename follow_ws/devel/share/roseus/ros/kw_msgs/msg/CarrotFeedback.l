;; Auto-generated. Do not edit!


(when (boundp 'kw_msgs::CarrotFeedback)
  (if (not (find-package "KW_MSGS"))
    (make-package "KW_MSGS"))
  (shadow 'CarrotFeedback (find-package "KW_MSGS")))
(unless (find-package "KW_MSGS::CARROTFEEDBACK")
  (make-package "KW_MSGS::CARROTFEEDBACK"))

(in-package "ROS")
;;//! \htmlinclude CarrotFeedback.msg.html


(defclass kw_msgs::CarrotFeedback
  :super ros::object
  :slots (_remaining _current ))

(defmethod kw_msgs::CarrotFeedback
  (:init
   (&key
    ((:remaining __remaining) 0)
    ((:current __current) 0)
    )
   (send-super :init)
   (setq _remaining (round __remaining))
   (setq _current (round __current))
   self)
  (:remaining
   (&optional __remaining)
   (if __remaining (setq _remaining __remaining)) _remaining)
  (:current
   (&optional __current)
   (if __current (setq _current __current)) _current)
  (:serialization-length
   ()
   (+
    ;; int64 _remaining
    8
    ;; int64 _current
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _remaining
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _remaining (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _remaining) (= (length (_remaining . bv)) 2)) ;; bignum
              (write-long (ash (elt (_remaining . bv) 0) 0) s)
              (write-long (ash (elt (_remaining . bv) 1) -1) s))
             ((and (class _remaining) (= (length (_remaining . bv)) 1)) ;; big1
              (write-long (elt (_remaining . bv) 0) s)
              (write-long (if (>= _remaining 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _remaining s)(write-long (if (>= _remaining 0) 0 #xffffffff) s)))
     ;; int64 _current
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _current (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _current) (= (length (_current . bv)) 2)) ;; bignum
              (write-long (ash (elt (_current . bv) 0) 0) s)
              (write-long (ash (elt (_current . bv) 1) -1) s))
             ((and (class _current) (= (length (_current . bv)) 1)) ;; big1
              (write-long (elt (_current . bv) 0) s)
              (write-long (if (>= _current 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _current s)(write-long (if (>= _current 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _remaining
#+(or :alpha :irix6 :x86_64)
      (setf _remaining (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _remaining (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _current
#+(or :alpha :irix6 :x86_64)
      (setf _current (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _current (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get kw_msgs::CarrotFeedback :md5sum-) "36a3eb3d921af7db8b535add2ff4e974")
(setf (get kw_msgs::CarrotFeedback :datatype-) "kw_msgs/CarrotFeedback")
(setf (get kw_msgs::CarrotFeedback :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
# Define the feedback
int64 remaining
int64 current

")



(provide :kw_msgs/CarrotFeedback "36a3eb3d921af7db8b535add2ff4e974")


