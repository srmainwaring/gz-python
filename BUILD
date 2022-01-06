#———————————————————————————————————————————————————————————————————————
# C++ binary

# Quick check of dependencies on third-party packages
cc_binary(
  name = "deps_check",
  srcs = ["deps_check.cc"],
  deps = [
    "//ign_utils:ign_utils",
    "//ign_math:ign_math",
    "//ign_math:libignition-math6.so",
    "@tinyxml2",
    "@sqlite3",
    "@zmq",
    "@zip",
    "@yaml",
    "@curl",
    "@json",
    "@glib",
    "@gts",
    "@freeimage",
    # "@gl",
    # "@X//:Xaw",
  ],
  visibility = ["//visibility:public"],
)
