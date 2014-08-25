# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "kurosp: 4 messages, 2 services")

set(MSG_I_FLAGS "-Ikurosp:/home/mh/catkin_ws/src/kurosp/msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Itrajectory_msgs:/opt/ros/indigo/share/trajectory_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(kurosp_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg" NAME_WE)
add_custom_target(_kurosp_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kurosp" "/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg" ""
)

get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/srv/BlockSendTrajectory.srv" NAME_WE)
add_custom_target(_kurosp_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kurosp" "/home/mh/catkin_ws/src/kurosp/srv/BlockSendTrajectory.srv" "kurosp/XyzYprTrajectory:kurosp/XyzYpr:kurosp/Info"
)

get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg" NAME_WE)
add_custom_target(_kurosp_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kurosp" "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg" "kurosp/XyzYpr:kurosp/Info"
)

get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/srv/SendTrajectory.srv" NAME_WE)
add_custom_target(_kurosp_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kurosp" "/home/mh/catkin_ws/src/kurosp/srv/SendTrajectory.srv" "kurosp/XyzYprTrajectory:kurosp/XyzYpr:kurosp/Info"
)

get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/Info.msg" NAME_WE)
add_custom_target(_kurosp_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kurosp" "/home/mh/catkin_ws/src/kurosp/msg/Info.msg" ""
)

get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYprState.msg" NAME_WE)
add_custom_target(_kurosp_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kurosp" "/home/mh/catkin_ws/src/kurosp/msg/XyzYprState.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kurosp
)
_generate_msg_cpp(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg"
  "${MSG_I_FLAGS}"
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg;/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kurosp
)
_generate_msg_cpp(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kurosp
)
_generate_msg_cpp(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kurosp
)

### Generating Services
_generate_srv_cpp(kurosp
  "/home/mh/catkin_ws/src/kurosp/srv/SendTrajectory.srv"
  "${MSG_I_FLAGS}"
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg;/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg;/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kurosp
)
_generate_srv_cpp(kurosp
  "/home/mh/catkin_ws/src/kurosp/srv/BlockSendTrajectory.srv"
  "${MSG_I_FLAGS}"
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg;/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg;/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kurosp
)

### Generating Module File
_generate_module_cpp(kurosp
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kurosp
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(kurosp_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(kurosp_generate_messages kurosp_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_cpp _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/srv/BlockSendTrajectory.srv" NAME_WE)
add_dependencies(kurosp_generate_messages_cpp _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_cpp _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/srv/SendTrajectory.srv" NAME_WE)
add_dependencies(kurosp_generate_messages_cpp _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/Info.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_cpp _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYprState.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_cpp _kurosp_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kurosp_gencpp)
add_dependencies(kurosp_gencpp kurosp_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kurosp_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kurosp
)
_generate_msg_lisp(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg"
  "${MSG_I_FLAGS}"
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg;/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kurosp
)
_generate_msg_lisp(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kurosp
)
_generate_msg_lisp(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kurosp
)

### Generating Services
_generate_srv_lisp(kurosp
  "/home/mh/catkin_ws/src/kurosp/srv/SendTrajectory.srv"
  "${MSG_I_FLAGS}"
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg;/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg;/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kurosp
)
_generate_srv_lisp(kurosp
  "/home/mh/catkin_ws/src/kurosp/srv/BlockSendTrajectory.srv"
  "${MSG_I_FLAGS}"
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg;/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg;/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kurosp
)

### Generating Module File
_generate_module_lisp(kurosp
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kurosp
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(kurosp_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(kurosp_generate_messages kurosp_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_lisp _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/srv/BlockSendTrajectory.srv" NAME_WE)
add_dependencies(kurosp_generate_messages_lisp _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_lisp _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/srv/SendTrajectory.srv" NAME_WE)
add_dependencies(kurosp_generate_messages_lisp _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/Info.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_lisp _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYprState.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_lisp _kurosp_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kurosp_genlisp)
add_dependencies(kurosp_genlisp kurosp_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kurosp_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kurosp
)
_generate_msg_py(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg"
  "${MSG_I_FLAGS}"
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg;/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kurosp
)
_generate_msg_py(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kurosp
)
_generate_msg_py(kurosp
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kurosp
)

### Generating Services
_generate_srv_py(kurosp
  "/home/mh/catkin_ws/src/kurosp/srv/SendTrajectory.srv"
  "${MSG_I_FLAGS}"
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg;/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg;/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kurosp
)
_generate_srv_py(kurosp
  "/home/mh/catkin_ws/src/kurosp/srv/BlockSendTrajectory.srv"
  "${MSG_I_FLAGS}"
  "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg;/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg;/home/mh/catkin_ws/src/kurosp/msg/Info.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kurosp
)

### Generating Module File
_generate_module_py(kurosp
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kurosp
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(kurosp_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(kurosp_generate_messages kurosp_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_py _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/srv/BlockSendTrajectory.srv" NAME_WE)
add_dependencies(kurosp_generate_messages_py _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYprTrajectory.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_py _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/srv/SendTrajectory.srv" NAME_WE)
add_dependencies(kurosp_generate_messages_py _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/Info.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_py _kurosp_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mh/catkin_ws/src/kurosp/msg/XyzYprState.msg" NAME_WE)
add_dependencies(kurosp_generate_messages_py _kurosp_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kurosp_genpy)
add_dependencies(kurosp_genpy kurosp_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kurosp_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kurosp)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kurosp
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(kurosp_generate_messages_cpp geometry_msgs_generate_messages_cpp)
add_dependencies(kurosp_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(kurosp_generate_messages_cpp trajectory_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kurosp)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kurosp
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(kurosp_generate_messages_lisp geometry_msgs_generate_messages_lisp)
add_dependencies(kurosp_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(kurosp_generate_messages_lisp trajectory_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kurosp)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kurosp\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kurosp
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(kurosp_generate_messages_py geometry_msgs_generate_messages_py)
add_dependencies(kurosp_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(kurosp_generate_messages_py trajectory_msgs_generate_messages_py)
