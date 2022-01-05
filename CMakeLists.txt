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

#============================================================================
# Find google abseil
# 
# macOS: $ brew install abseil
# 
find_package(absl REQUIRED)

#============================================================================
# Find pybind11
# 
# macOS: $ brew install python
# macOS: $ brew install pybind11
# 
find_package(Python COMPONENTS Interpreter Development)
find_package(pybind11 CONFIG)

#============================================================================
# subdirectories for external dependencies and protobuf definitions

add_subdirectory(external)
add_subdirectory(proto)

#============================================================================
# msgs_tools

add_library(msgs_tools src/msgs_tools.cc)

target_link_libraries(msgs_tools ign_proto ${PROTOBUF_LIBRARY})

target_include_directories(msgs_tools
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/include
    ${Protobuf_INCLUDE_DIR}
)

#============================================================================
# ignition_msgs Python extension module

pybind11_add_module(msgs_tools_module MODULE
  src/pybind11/msgs_tools_module.cc
)

target_include_directories(msgs_tools_module
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/external/pybind11_protobuf
    ${PROJECT_SOURCE_DIR}/include
    ${PROTOBUF_INCLUDE_DIR}
)
  
target_link_libraries(msgs_tools_module
  PRIVATE
    pybind11_native_proto_caster
    pybind11_proto
    pybind11_proto_utils
    pybind11_proto_cast_util
    ign_proto
    msgs_tools
)

add_dependencies(msgs_tools_module msgs_tools)

#============================================================================
# main

add_executable(main src/main.cc)

target_link_libraries(main ign_proto msgs_tools ${PROTOBUF_LIBRARY})

target_include_directories(main
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/include
    ${Protobuf_INCLUDE_DIR}
)
