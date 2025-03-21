# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CIS5600-Proj02-SceneGraph_autogen"
  "CMakeFiles\\CIS5600-Proj02-SceneGraph_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CIS5600-Proj02-SceneGraph_autogen.dir\\ParseCache.txt"
  )
endif()
