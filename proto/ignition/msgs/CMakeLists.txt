#============================================================================
# ign-msgs generate protobuf Python bindings

# Get the proto files from the installed location of ign-msgs
file(GLOB PROTO_FILES ${ignition-msgs${IGN_MSGS_VER}_INCLUDE_DIRS}/ignition/msgs/*.proto)

# Make a local copy in ./build/ignition/msgs 
list(APPEND PROTO_FILES_COPY)
foreach(PROTO_FILE ${PROTO_FILES})
  get_filename_component(PROTO_NAME ${PROTO_FILE} NAME)
  set(PROTO_FILE_COPY ${CMAKE_CURRENT_BINARY_DIR}/${PROTO_NAME})
  configure_file(${PROTO_FILE} ${PROTO_FILE_COPY} COPYONLY)
  list(APPEND PROTO_FILES_COPY ${PROTO_FILE_COPY})
endforeach()

# Generate bindings for each file
# 
# Note use of IMPORT_DIRS (not in CMake documentation)
# https://stackoverflow.com/questions/61638851/cmake-3-1-protobuf-import-dirs-importing-another-proto-error
# 
# foreach(PROTO_FILE ${PROTO_FILES_COPY})
#   get_filename_component(TARGET_PREFIX ${PROTO_FILE} NAME_WE)
#   protobuf_generate_python(PROTO_PY
#     ${PROTO_FILE}
#     IMPORT_DIRS ${CMAKE_CURRENT_BINARY_DIR}/../..  
#   )
#   add_custom_target(${TARGET_PREFIX}_py_pb2 ALL
#     DEPENDS ${PROTO_PY}
#   )
# endforeach()


# TODO(srmainwaring): generated protobufs still not correct.
#     Issue with import paths...
# 
set(Protobuf_IMPORT_DIRS ${CMAKE_CURRENT_BINARY_DIR}/..)

protobuf_generate_python(TIME_PROTO_PY
  ${CMAKE_CURRENT_BINARY_DIR}/time.proto
)

add_custom_target(time_py_pb2 ALL
  DEPENDS ${TIME_PROTO_PY}
)

protobuf_generate_python(HEADER_PROTO_PY
  ${CMAKE_CURRENT_BINARY_DIR}/header.proto
)

add_custom_target(header_py_pb2 ALL
  DEPENDS ${HEADER_PROTO_PY}
)

protobuf_generate_python(VECTOR3D_PROTO_PY
  ${CMAKE_CURRENT_BINARY_DIR}/vector3d.proto
)

add_custom_target(vector3d_py_pb2 ALL
  DEPENDS ${VECTOR3D_PROTO_PY}
)