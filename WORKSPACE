workspace(name = "python-ignition")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

# `abseil-cpp` required by `pybind11_protobuf`
http_archive(
    name = "com_google_absl",
    sha256 = "dcf71b9cba8dc0ca9940c4b316a0c796be8fab42b070bb6b7cab62b48f0e66c4",  # SHARED_ABSL_SHA
    strip_prefix = "abseil-cpp-20211102.0",
    urls = [
        "https://github.com/abseil/abseil-cpp/archive/refs/tags/20211102.0.tar.gz",
    ],
)

# `pybind11_bazel`
http_archive(
  name = "pybind11_bazel",
  strip_prefix = "pybind11_bazel-72cbbf1fbc830e487e3012862b7b720001b70672",
  sha256 = "516c1b3a10d87740d2b7de6f121f8e19dde2c372ecbfe59aef44cd1872c10395",
  urls = ["https://github.com/pybind/pybind11_bazel/archive/72cbbf1fbc830e487e3012862b7b720001b70672.tar.gz"],
)

# `pybind11`
http_archive(
  name = "pybind11",
  build_file = "@pybind11_bazel//:pybind11.BUILD",
  strip_prefix = "pybind11-2.9.0",
  sha256 = "057fb68dafd972bc13afb855f3b0d8cf0fa1a78ef053e815d9af79be7ff567cb",
  urls = ["https://github.com/pybind/pybind11/archive/refs/tags/v2.9.0.tar.gz"],
)

load("@pybind11_bazel//:python_configure.bzl", "python_configure")
python_configure(name = "local_config_python")

# `pybind11_protobuf`
git_repository(
    name = "pybind11_protobuf",
    commit = "30f02dd9ccd2fc7046c36ed913ed510fd1aa7301", # Latest (2022-01-05)
    remote = "https://github.com/pybind/pybind11_protobuf.git",
)

# proto_library, cc_proto_library, and java_proto_library rules implicitly
# depend on @com_google_protobuf for protoc and proto runtimes.
# This statement defines the @com_google_protobuf repo.
# 
# The patch is required for @pybind11_protobuf//:pybind11_protobuf:proto_cast_util
# 
http_archive(
    name = "com_google_protobuf",
    sha256 = "87407cd28e7a9c95d9f61a098a53cf031109d451a7763e7dd1253abf8b4df422",
    strip_prefix = "protobuf-3.19.1",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/v3.19.1.tar.gz"],
    patches = [
        "com_google_protobuf_build.patch",
    ],
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()

# GRPC v1.42, for proto rules.
# For a related discussion of the pro/cons of various open-source py proto rule
# repositories, see b/189457935.
# http_archive(
#     name = "com_github_grpc_grpc",
#     sha256 = "9f387689b7fdf6c003fd90ef55853107f89a2121792146770df5486f0199f400",
#     strip_prefix = "grpc-1.42.0",
#     urls = ["https://github.com/grpc/grpc/archive/v1.42.0.zip"],
# )

# load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
# grpc_deps()

# Protobuf and gRPC rules for Bazel
# https://rules-proto-grpc.com/en/latest/index.html
http_archive(
    name = "rules_proto_grpc",
    sha256 = "507e38c8d95c7efa4f3b1c0595a8e8f139c885cb41a76cab7e20e4e67ae87731",
    strip_prefix = "rules_proto_grpc-4.1.1",
    urls = ["https://github.com/rules-proto-grpc/rules_proto_grpc/archive/4.1.1.tar.gz"],
)

load("@rules_proto_grpc//:repositories.bzl", "rules_proto_grpc_toolchains", "rules_proto_grpc_repos")
rules_proto_grpc_toolchains()
rules_proto_grpc_repos()

load("@rules_proto_grpc//cpp:repositories.bzl", "cpp_repos")
cpp_repos()

load("@rules_proto_grpc//python:repositories.bzl", rules_proto_grpc_python_repos = "python_repos")
rules_proto_grpc_python_repos()

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

# required when using --define use_fast_cpp_protos=true
bind(
    name = "python_headers",
    actual = "@local_config_python//:python_headers",
)

# `ign-msgs9`
# https://stackoverflow.com/questions/50592846/pull-github-repository-using-bazel
# strip the `proto` prefix so that generated protobuf bindings for ignition-msgs
# have the correct include path which is `ignition.msgs`
new_git_repository(
    name = "ign-msgs9",
    commit = "6da277056e867e8b60c0b48ff88df9b3c5a49c9a", # Latest (2022-01-01)
    remote = "https://github.com/ignitionrobotics/ign-msgs.git",
    strip_prefix = "proto",
    build_file = "//:ign-msgs9.BUILD"
)

# `ign-transport12`
git_repository(
    name = "ign-transport12",
    commit = "185961ff1c97583c50d67c65a5b0c9bb9c64f5d5", # Latest (2022-01-01)
    remote = "https://github.com/ignitionrobotics/ign-transport.git",
)
