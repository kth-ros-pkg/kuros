; Auto-generated. Do not edit!


(cl:in-package kurosp-srv)


;//! \htmlinclude BlockSendTrajectory-request.msg.html

(cl:defclass <BlockSendTrajectory-request> (roslisp-msg-protocol:ros-message)
  ((trajectory
    :reader trajectory
    :initarg :trajectory
    :type kurosp-msg:XyzYprTrajectory
    :initform (cl:make-instance 'kurosp-msg:XyzYprTrajectory)))
)

(cl:defclass BlockSendTrajectory-request (<BlockSendTrajectory-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BlockSendTrajectory-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BlockSendTrajectory-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kurosp-srv:<BlockSendTrajectory-request> is deprecated: use kurosp-srv:BlockSendTrajectory-request instead.")))

(cl:ensure-generic-function 'trajectory-val :lambda-list '(m))
(cl:defmethod trajectory-val ((m <BlockSendTrajectory-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kurosp-srv:trajectory-val is deprecated.  Use kurosp-srv:trajectory instead.")
  (trajectory m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BlockSendTrajectory-request>) ostream)
  "Serializes a message object of type '<BlockSendTrajectory-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'trajectory) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BlockSendTrajectory-request>) istream)
  "Deserializes a message object of type '<BlockSendTrajectory-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'trajectory) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BlockSendTrajectory-request>)))
  "Returns string type for a service object of type '<BlockSendTrajectory-request>"
  "kurosp/BlockSendTrajectoryRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BlockSendTrajectory-request)))
  "Returns string type for a service object of type 'BlockSendTrajectory-request"
  "kurosp/BlockSendTrajectoryRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BlockSendTrajectory-request>)))
  "Returns md5sum for a message object of type '<BlockSendTrajectory-request>"
  "244e5565eb5f6feacf78a0491f04db4a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BlockSendTrajectory-request)))
  "Returns md5sum for a message object of type 'BlockSendTrajectory-request"
  "244e5565eb5f6feacf78a0491f04db4a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BlockSendTrajectory-request>)))
  "Returns full string definition for message of type '<BlockSendTrajectory-request>"
  (cl:format cl:nil "XyzYprTrajectory trajectory~%~%================================================================================~%MSG: kurosp/XyzYprTrajectory~%Info info~%XyzYpr[] frames~%~%================================================================================~%MSG: kurosp/Info~%uint8 response_mode #= 3 # KUKA_RMODE_STREAM~%uint32 response_ms #= 20 # [ms]~%uint32 traj_id #= 666 # a trajectory id~%bool run #= 1 # YES~%uint32 vel #= 200 # [mm/s]~%uint32 tol #= 20 # [mm]~%uint8 frame_type #= 1 # KUKA_CARTESIAN~%~%================================================================================~%MSG: kurosp/XyzYpr~%float64[6] xyzypr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BlockSendTrajectory-request)))
  "Returns full string definition for message of type 'BlockSendTrajectory-request"
  (cl:format cl:nil "XyzYprTrajectory trajectory~%~%================================================================================~%MSG: kurosp/XyzYprTrajectory~%Info info~%XyzYpr[] frames~%~%================================================================================~%MSG: kurosp/Info~%uint8 response_mode #= 3 # KUKA_RMODE_STREAM~%uint32 response_ms #= 20 # [ms]~%uint32 traj_id #= 666 # a trajectory id~%bool run #= 1 # YES~%uint32 vel #= 200 # [mm/s]~%uint32 tol #= 20 # [mm]~%uint8 frame_type #= 1 # KUKA_CARTESIAN~%~%================================================================================~%MSG: kurosp/XyzYpr~%float64[6] xyzypr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BlockSendTrajectory-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'trajectory))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BlockSendTrajectory-request>))
  "Converts a ROS message object to a list"
  (cl:list 'BlockSendTrajectory-request
    (cl:cons ':trajectory (trajectory msg))
))
;//! \htmlinclude BlockSendTrajectory-response.msg.html

(cl:defclass <BlockSendTrajectory-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass BlockSendTrajectory-response (<BlockSendTrajectory-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BlockSendTrajectory-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BlockSendTrajectory-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kurosp-srv:<BlockSendTrajectory-response> is deprecated: use kurosp-srv:BlockSendTrajectory-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <BlockSendTrajectory-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kurosp-srv:success-val is deprecated.  Use kurosp-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BlockSendTrajectory-response>) ostream)
  "Serializes a message object of type '<BlockSendTrajectory-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BlockSendTrajectory-response>) istream)
  "Deserializes a message object of type '<BlockSendTrajectory-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BlockSendTrajectory-response>)))
  "Returns string type for a service object of type '<BlockSendTrajectory-response>"
  "kurosp/BlockSendTrajectoryResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BlockSendTrajectory-response)))
  "Returns string type for a service object of type 'BlockSendTrajectory-response"
  "kurosp/BlockSendTrajectoryResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BlockSendTrajectory-response>)))
  "Returns md5sum for a message object of type '<BlockSendTrajectory-response>"
  "244e5565eb5f6feacf78a0491f04db4a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BlockSendTrajectory-response)))
  "Returns md5sum for a message object of type 'BlockSendTrajectory-response"
  "244e5565eb5f6feacf78a0491f04db4a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BlockSendTrajectory-response>)))
  "Returns full string definition for message of type '<BlockSendTrajectory-response>"
  (cl:format cl:nil "bool success~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BlockSendTrajectory-response)))
  "Returns full string definition for message of type 'BlockSendTrajectory-response"
  (cl:format cl:nil "bool success~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BlockSendTrajectory-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BlockSendTrajectory-response>))
  "Converts a ROS message object to a list"
  (cl:list 'BlockSendTrajectory-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'BlockSendTrajectory)))
  'BlockSendTrajectory-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'BlockSendTrajectory)))
  'BlockSendTrajectory-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BlockSendTrajectory)))
  "Returns string type for a service object of type '<BlockSendTrajectory>"
  "kurosp/BlockSendTrajectory")