
(cl:in-package :asdf)

(defsystem "kurosp-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :kurosp-msg
)
  :components ((:file "_package")
    (:file "SendTrajectory" :depends-on ("_package_SendTrajectory"))
    (:file "_package_SendTrajectory" :depends-on ("_package"))
    (:file "BlockSendTrajectory" :depends-on ("_package_BlockSendTrajectory"))
    (:file "_package_BlockSendTrajectory" :depends-on ("_package"))
  ))