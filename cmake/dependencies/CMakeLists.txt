include(FetchContent)

#============================================================================
# Declare all dependencies first

if(BUILD_protobuf)
  set(protobuf_BUILD_TESTS OFF CACHE INTERNAL "")
  FetchContent_Declare(
    protobuf
    GIT_REPOSITORY "https://github.com/protocolbuffers/protobuf.git"
    GIT_TAG "3d995aaf98ed73ddcbbf0ed88d82bbbf80ec8cf9"
    GIT_SUBMODULES ""
  )
endif()

if(BUILD_pybind11_protobuf)
  FetchContent_Declare(
    pybind11_protobuf
    GIT_REPOSITORY "https://github.com/srmainwaring/pybind11_protobuf"
    GIT_TAG "dc339ed4b5ed5b8bd90aee3f9958c90bb45f1c31"
  )
endif()

#============================================================================
# Make dependencies avaialble

if(BUILD_protobuf)
  message(CHECK_START "Fetching protobuf")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  FetchContent_MakeAvailable(protobuf)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()

if(BUILD_pybind11_protobuf)
  message(CHECK_START "Fetching pybind11_protobuf")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  FetchContent_MakeAvailable(pybind11_protobuf)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()

