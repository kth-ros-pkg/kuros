; Auto-generated. Do not edit!


(cl:in-package kurosp-msg)


;//! \htmlinclude XyzYprTrajectory.msg.html

(cl:defclass <XyzYprTrajectory> (roslisp-msg-protocol:ros-message)
  ((info
    :reader info
    :initarg :info
    :type kurosp-msg:Info
    :initform (cl:make-instance 'kurosp-msg:Info))
   (frames
    :reader frames
    :initarg :frames
    :type (cl:vector kurosp-msg:XyzYpr)
   :initform (cl:make-array 0 :element-type 'kurosp-msg:XyzYpr :initial-element (cl:make-instance 'kurosp-msg:XyzYpr))))
)

(cl:defclass XyzYprTrajectory (<XyzYprTrajectory>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <XyzYprTrajectory>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'XyzYprTrajectory)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kurosp-msg:<XyzYprTrajectory> is deprecated: use kurosp-msg:XyzYprTrajectory instead.")))

(cl:ensure-generic-function 'info-val :lambda-list '(m))
(cl:defmethod info-val ((m <XyzYprTrajectory>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kurosp-msg:info-val is deprecated.  Use kurosp-msg:info instead.")
  (info m))

(cl:ensure-generic-function 'frames-val :lambda-list '(m))
(cl:defmethod frames-val ((m <XyzYprTrajectory>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kurosp-msg:frames-val is deprecated.  Use kurosp-msg:frames instead.")
  (frames m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <XyzYprTrajectory>) ostream)
  "Serializes a message object of type '<XyzYprTrajectory>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'info) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'frames))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'frames))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <XyzYprTrajectory>) istream)
  "Deserializes a message object of type '<XyzYprTrajectory>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'info) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'frames) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'frames)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'kurosp-msg:XyzYpr))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<XyzYprTrajectory>)))
  "Returns string type for a message object of type '<XyzYprTrajectory>"
  "kurosp/XyzYprTrajectory")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'XyzYprTrajectory)))
  "Returns string type for a message object of type 'XyzYprTrajectory"
  "kurosp/XyzYprTrajectory")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<XyzYprTrajectory>)))
  "Returns md5sum for a message object of type '<XyzYprTrajectory>"
  "1c5a80a148196559c67debf2f7d074e4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'XyzYprTrajectory)))
  "Returns md5sum for a message object of type 'XyzYprTrajectory"
  "1c5a80a148196559c67debf2f7d074e4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<XyzYprTrajectory>)))
  "Returns full string definition for message of type '<XyzYprTrajectory>"
  (cl:format cl:nil "Info info~%XyzYpr[] frames~%~%================================================================================~%MSG: kurosp/Info~%uint8 response_mode #= 3 # KUKA_RMODE_STREAM~%uint32 response_ms #= 20 # [ms]~%uint32 traj_id #= 666 # a trajectory id~%bool run #= 1 # YES~%uint32 vel #= 200 # [mm/s]~%uint32 tol #= 20 # [mm]~%uint8 frame_type #= 1 # KUKA_CARTESIAN~%~%================================================================================~%MSG: kurosp/XyzYpr~%float64[6] xyzypr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'XyzYprTrajectory)))
  "Returns full string definition for message of type 'XyzYprTrajectory"
  (cl:format cl:nil "Info info~%XyzYpr[] frames~%~%================================================================================~%MSG: kurosp/Info~%uint8 response_mode #= 3 # KUKA_RMODE_STREAM~%uint32 response_ms #= 20 # [ms]~%uint32 traj_id #= 666 # a trajectory id~%bool run #= 1 # YES~%uint32 vel #= 200 # [mm/s]~%uint32 tol #= 20 # [mm]~%uint8 frame_type #= 1 # KUKA_CARTESIAN~%~%================================================================================~%MSG: kurosp/XyzYpr~%float64[6] xyzypr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <XyzYprTrajectory>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'info))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'frames) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <XyzYprTrajectory>))
  "Converts a ROS message object to a list"
  (cl:list 'XyzYprTrajectory
    (cl:cons ':info (info msg))
    (cl:cons ':frames (frames msg))
))
