; Auto-generated. Do not edit!


(cl:in-package kurosp-msg)


;//! \htmlinclude XyzYpr.msg.html

(cl:defclass <XyzYpr> (roslisp-msg-protocol:ros-message)
  ((xyzypr
    :reader xyzypr
    :initarg :xyzypr
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass XyzYpr (<XyzYpr>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <XyzYpr>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'XyzYpr)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kurosp-msg:<XyzYpr> is deprecated: use kurosp-msg:XyzYpr instead.")))

(cl:ensure-generic-function 'xyzypr-val :lambda-list '(m))
(cl:defmethod xyzypr-val ((m <XyzYpr>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kurosp-msg:xyzypr-val is deprecated.  Use kurosp-msg:xyzypr instead.")
  (xyzypr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <XyzYpr>) ostream)
  "Serializes a message object of type '<XyzYpr>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'xyzypr))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <XyzYpr>) istream)
  "Deserializes a message object of type '<XyzYpr>"
  (cl:setf (cl:slot-value msg 'xyzypr) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'xyzypr)))
    (cl:dotimes (i 6)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<XyzYpr>)))
  "Returns string type for a message object of type '<XyzYpr>"
  "kurosp/XyzYpr")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'XyzYpr)))
  "Returns string type for a message object of type 'XyzYpr"
  "kurosp/XyzYpr")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<XyzYpr>)))
  "Returns md5sum for a message object of type '<XyzYpr>"
  "db1a4820a973384f560b344883116cc9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'XyzYpr)))
  "Returns md5sum for a message object of type 'XyzYpr"
  "db1a4820a973384f560b344883116cc9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<XyzYpr>)))
  "Returns full string definition for message of type '<XyzYpr>"
  (cl:format cl:nil "float64[6] xyzypr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'XyzYpr)))
  "Returns full string definition for message of type 'XyzYpr"
  (cl:format cl:nil "float64[6] xyzypr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <XyzYpr>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'xyzypr) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <XyzYpr>))
  "Converts a ROS message object to a list"
  (cl:list 'XyzYpr
    (cl:cons ':xyzypr (xyzypr msg))
))
