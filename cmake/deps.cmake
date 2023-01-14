if(NOT BUILD_protobuf)
  find_package(protobuf REQUIRED)
endif()

if(NOT BUILD_pybind11_protobuf)
  find_package(pybind11_protobuf REQUIRED)
endif()

