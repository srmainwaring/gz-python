cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

project(protobuf_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#============================================================================
# Find protobuf
# 
# macOS: $ brew install protobuf
# 
find_package(Protobuf REQUIRED)
# message("Protobuf_FOUND: ${Protobuf_FOUND}")
# message("Protobuf_VERSION: ${Protobuf_VERSION}")
# message("Protobuf_LIBRARY: ${Protobuf_LIBRARY}")
# message("Protobuf_INCLUDE_DIR: ${Protobuf_INCLUDE_DIR}")

#============================================================================
# Find google abseil
# 
# macOS: $ brew install abseil
# 
# find_package(absl REQUIRED)

#============================================================================
# Find pybind11
# 
# macOS: $ brew install python
# macOS: $ brew install pybind11
# 
find_package(Python COMPONENTS Interpreter Development)
# find_package(pybind11 CONFIG)

#============================================================================
# Find the ign-msgs library
set(IGN_MSGS_VER 9)
find_package(ignition-msgs${IGN_MSGS_VER} REQUIRED)

# Find the ign-transport library
set(IGN_TRANSPORT_VER 12)
find_package(ignition-transport${IGN_TRANSPORT_VER} REQUIRED)

#============================================================================
# subdirectories for external dependencies

add_subdirectory(external)

#============================================================================
# ignition_msgs_lib C++ library

add_library(ignition_msgs_lib SHARED
  src/ignition_msgs.cc
)

target_link_libraries(ignition_msgs_lib
  ignition-msgs${IGN_MSGS_VER}::ignition-msgs${IGN_MSGS_VER}
)

target_include_directories(ignition_msgs_lib
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

#============================================================================
# ignition_msgs Python extension module

pybind11_add_module(ignition_msgs MODULE
  src/pybind11/ignition_msgs.cc
)

target_link_libraries(ignition_msgs
  PRIVATE
    ignition_msgs_lib
    ${Protobuf_LIBRARY}
    pybind11_native_proto_caster
)

target_include_directories(ignition_msgs
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/external/pybind11_protobuf
)

add_dependencies(ignition_msgs
  ignition_msgs_lib
)

#============================================================================
# ignition_transport Python extension module

pybind11_add_module(ignition_transport MODULE
  src/pybind11/ignition_transport.cc
)

target_link_libraries(ignition_transport
  PRIVATE
    ignition-msgs${IGN_MSGS_VER}::ignition-msgs${IGN_MSGS_VER}
    ignition-transport${IGN_TRANSPORT_VER}::ignition-transport${IGN_TRANSPORT_VER}
    ${Protobuf_LIBRARY}
    pybind11_native_proto_caster
)

target_include_directories(ignition_transport
  PRIVATE
    ${Protobuf_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/external/pybind11_protobuf
)

#============================================================================
# main

add_executable(main src/main.cc)

target_link_libraries(main
  ignition_msgs_lib
  ignition-msgs${IGN_MSGS_VER}::ignition-msgs${IGN_MSGS_VER}
)

target_include_directories(main
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

add_dependencies(main
  ignition_msgs_lib
)

#============================================================================
# msg_example

add_executable(msg_example src/msg_example.cc)

target_link_libraries(msg_example
  ignition-msgs${IGN_MSGS_VER}::ignition-msgs${IGN_MSGS_VER}
)

#============================================================================
# publisher

add_executable(publisher src/publisher.cc)

target_link_libraries(publisher
  ignition-msgs${IGN_MSGS_VER}::ignition-msgs${IGN_MSGS_VER}
  ignition-transport${IGN_TRANSPORT_VER}::ignition-transport${IGN_TRANSPORT_VER}
)

#============================================================================
# subscriber

add_executable(subscriber src/subscriber.cc)

target_link_libraries(subscriber
  ignition-msgs${IGN_MSGS_VER}::ignition-msgs${IGN_MSGS_VER}
  ignition-transport${IGN_TRANSPORT_VER}::ignition-transport${IGN_TRANSPORT_VER}
)

#============================================================================
# rover_publisher

add_executable(rover_publisher src/rover_publisher.cc)

target_link_libraries(rover_publisher
  ignition-msgs${IGN_MSGS_VER}::ignition-msgs${IGN_MSGS_VER}
  ignition-transport${IGN_TRANSPORT_VER}::ignition-transport${IGN_TRANSPORT_VER}
)

#============================================================================
# rover_subscriber

add_executable(rover_subscriber src/rover_subscriber.cc)

target_link_libraries(rover_subscriber
  ignition-msgs${IGN_MSGS_VER}::ignition-msgs${IGN_MSGS_VER}
  ignition-transport${IGN_TRANSPORT_VER}::ignition-transport${IGN_TRANSPORT_VER}
)

#============================================================================
# ign_topic_echo

add_executable(ign_topic_echo src/ign_topic_echo.cc)

target_link_libraries(ign_topic_echo
  ignition-msgs${IGN_MSGS_VER}::ignition-msgs${IGN_MSGS_VER}
  ignition-transport${IGN_TRANSPORT_VER}::ignition-transport${IGN_TRANSPORT_VER}
)

#============================================================================
# generate protobuf Python bindings

add_subdirectory(proto/ignition/msgs)

