include(FetchContent)

#============================================================================
# Declare all dependencies first

find_package(Protobuf ${_protobuf_version} EXACT QUIET)
if(NOT Protobuf_FOUND)
  set(protobuf_BUILD_TESTS OFF CACHE INTERNAL "")
  FetchContent_Declare(
    Protobuf
    GIT_REPOSITORY ${_protobuf_repository}
    GIT_TAG ${_protobuf_tag}
    GIT_SUBMODULES ""
  )
endif()

find_package(pybind11_protobuf ${_pybind11_protobuf_version} EXACT QUIET)
if(NOT pybind11_protobuf_FOUND)
  FetchContent_Declare(
    pybind11_protobuf
    GIT_REPOSITORY ${_pybind11_protobuf_repository}
    GIT_TAG ${_pybind11_protobuf_tag}
  )
endif()

#============================================================================
# Make dependencies avaialble

if(NOT Protobuf_FOUND)
  message(CHECK_START "Fetching Protobuf")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  FetchContent_MakeAvailable(Protobuf)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()

if(NOT pybind11_protobuf_FOUND)
  message(CHECK_START "Fetching pybind11_protobuf")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  FetchContent_MakeAvailable(pybind11_protobuf)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()

