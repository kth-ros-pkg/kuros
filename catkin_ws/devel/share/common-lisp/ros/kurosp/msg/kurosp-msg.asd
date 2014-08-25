
(cl:in-package :asdf)

(defsystem "kurosp-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "XyzYpr" :depends-on ("_package_XyzYpr"))
    (:file "_package_XyzYpr" :depends-on ("_package"))
    (:file "Trajectory" :depends-on ("_package_Trajectory"))
    (:file "_package_Trajectory" :depends-on ("_package"))
    (:file "Frame" :depends-on ("_package_Frame"))
    (:file "_package_Frame" :depends-on ("_package"))
    (:file "XyzYprTrajectory" :depends-on ("_package_XyzYprTrajectory"))
    (:file "_package_XyzYprTrajectory" :depends-on ("_package"))
    (:file "Info" :depends-on ("_package_Info"))
    (:file "_package_Info" :depends-on ("_package"))
    (:file "Ypr" :depends-on ("_package_Ypr"))
    (:file "_package_Ypr" :depends-on ("_package"))
    (:file "XyzYprState" :depends-on ("_package_XyzYprState"))
    (:file "_package_XyzYprState" :depends-on ("_package"))
  ))