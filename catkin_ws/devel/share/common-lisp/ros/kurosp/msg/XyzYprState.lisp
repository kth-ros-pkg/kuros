; Auto-generated. Do not edit!


(cl:in-package kurosp-msg)


;//! \htmlinclude XyzYprState.msg.html

(cl:defclass <XyzYprState> (roslisp-msg-protocol:ros-message)
  ((status
    :reader status
    :initarg :status
    :type cl:integer
    :initform 0)
   (id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0)
   (tick
    :reader tick
    :initarg :tick
    :type cl:integer
    :initform 0)
   (xyzypr
    :reader xyzypr
    :initarg :xyzypr
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass XyzYprState (<XyzYprState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <XyzYprState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'XyzYprState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kurosp-msg:<XyzYprState> is deprecated: use kurosp-msg:XyzYprState instead.")))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <XyzYprState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kurosp-msg:status-val is deprecated.  Use kurosp-msg:status instead.")
  (status m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <XyzYprState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kurosp-msg:id-val is deprecated.  Use kurosp-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'tick-val :lambda-list '(m))
(cl:defmethod tick-val ((m <XyzYprState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kurosp-msg:tick-val is deprecated.  Use kurosp-msg:tick instead.")
  (tick m))

(cl:ensure-generic-function 'xyzypr-val :lambda-list '(m))
(cl:defmethod xyzypr-val ((m <XyzYprState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kurosp-msg:xyzypr-val is deprecated.  Use kurosp-msg:xyzypr instead.")
  (xyzypr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <XyzYprState>) ostream)
  "Serializes a message object of type '<XyzYprState>"
  (cl:let* ((signed (cl:slot-value msg 'status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'tick)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <XyzYprState>) istream)
  "Deserializes a message object of type '<XyzYprState>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'status) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'tick) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<XyzYprState>)))
  "Returns string type for a message object of type '<XyzYprState>"
  "kurosp/XyzYprState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'XyzYprState)))
  "Returns string type for a message object of type 'XyzYprState"
  "kurosp/XyzYprState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<XyzYprState>)))
  "Returns md5sum for a message object of type '<XyzYprState>"
  "4ab2881d41b267db4a3a1e1808a48c72")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'XyzYprState)))
  "Returns md5sum for a message object of type 'XyzYprState"
  "4ab2881d41b267db4a3a1e1808a48c72")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<XyzYprState>)))
  "Returns full string definition for message of type '<XyzYprState>"
  (cl:format cl:nil "int32 status~%int32 id~%int32 tick~%float64[6] xyzypr~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'XyzYprState)))
  "Returns full string definition for message of type 'XyzYprState"
  (cl:format cl:nil "int32 status~%int32 id~%int32 tick~%float64[6] xyzypr~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <XyzYprState>))
  (cl:+ 0
     4
     4
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'xyzypr) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <XyzYprState>))
  "Converts a ROS message object to a list"
  (cl:list 'XyzYprState
    (cl:cons ':status (status msg))
    (cl:cons ':id (id msg))
    (cl:cons ':tick (tick msg))
    (cl:cons ':xyzypr (xyzypr msg))
))
