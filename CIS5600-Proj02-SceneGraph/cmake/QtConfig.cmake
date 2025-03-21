# Define Qt paths through environment variables or cache variables
if(NOT DEFINED ENV{QT6_MINGW_DIR})
  set(DEFAULT_QT_MINGW_PATH "E:/dev/libs/qt/6.2.2/mingw_64")
  if(EXISTS "${DEFAULT_QT_MINGW_PATH}")
    set(ENV{QT6_MINGW_DIR} "${DEFAULT_QT_MINGW_PATH}")
  else()
    message(WARNING "Default Qt MinGW path does not exist: ${DEFAULT_QT_MINGW_PATH}")
  endif()
endif()

if(NOT DEFINED ENV{QT6_MSVC_DIR})
  set(DEFAULT_QT_MSVC_PATH "E:/dev/libs/qt/6.2.2/msvc2019_64")
  if(EXISTS "${DEFAULT_QT_MSVC_PATH}")
    set(ENV{QT6_MSVC_DIR} "${DEFAULT_QT_MSVC_PATH}")
  else()
    message(WARNING "Default Qt MSVC path does not exist: ${DEFAULT_QT_MSVC_PATH}")
  endif()
endif()

# Path conversion only needed on Windows
if(WIN32)
  function(convert_to_cmake_path_format PATH)
    string(REPLACE "\\" "/" ${PATH} ${PATH})
  endfunction()
endif()

# Set Qt directory based on compiler
if(CMAKE_CXX_COMPILER MATCHES ".*g\\+\\+.*" OR CMAKE_CXX_COMPILER MATCHES ".*gcc.*")
  set(QT6_DIR ENV{QT6_MINGW_DIR})
elseif(CMAKE_CXX_COMPILER MATCHES ".*cl.*" OR CMAKE_CXX_COMPILER MATCHES ".*msvc.*")
  set(QT6_DIR ENV{QT6_MSVC_DIR})
else()
  message(FATAL_ERROR "Your Compiler: ${CMAKE_CXX_COMPILER} is not supported by QT")
endif()

# Convert paths if on Windows
if(WIN32)
  convert_to_cmake_path_format(${QT6_DIR})
endif()

# Set the Qt installation path
set(CMAKE_PREFIX_PATH ${QT6_DIR})



#########################################################################################
# Ending setting up QT6_DIR
#########################################################################################
