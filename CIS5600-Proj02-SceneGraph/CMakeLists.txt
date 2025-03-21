# LICENSE: MIT3.0
# This package is written by @Yueyang Li (Aeon) to find the Qt_6 installation
# in the current PC, one would either set the QT6_xxx_DIR in their environment variables, or
# set the variables manually here

cmake_minimum_required(VERSION 3.27)

# Get Current Directory Name
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Project Name and Languages
project(${PROJECT_NAME} LANGUAGES CXX)

# Include Configuration files
# Set the C++ Stanard C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "-g") # Set the debug flag

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/QtConfig.cmake)

# Finding project related packages
find_package(OpenGL REQUIRED) # Ensure that OpenGL is found
find_package(Qt6 # Package name
             6.2.2 # Minimum version required
        COMPONENTS
            Core    # QT Core, including slots features
            Widgets # UI Widgets(buttons, windows)
            Gui     # GUI functionality
            OpenGL  # Qt's OpenGL Support
            OpenGLWidgets # Qt widge for OpenGL Rendering
        REQUIRED)

# if packages not found, print the error message if needed
if(NOT Qt6_FOUND)
    message(FATAL_ERROR "QT6 not found")
endif()



# Add include directories
# PreProcessor needs to know where to find the header files
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

# Set the source file of the project
file(GLOB_RECURSE PROJECT_SOURCES
        src/*.cpp
        src/*.c
)

# Automatically run moc and uic on sources and headers
set(CMAKE_AUTOMOC ON) # automatically
set(CMAKE_AUTORCC ON) # automatically parse the qrc file
set(CMAKE_AUTOUIC ON) # automatically parse the qt headers file
set(CMAKE_AUTOUIC_SEARCH_PATHS ${PROJECT_SOURCE_DIR}/forms) # Set the search path for the ui files (!Important for Cmake to look for mainwindow.ui form)

# Add the executable targets
add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/glsl.qrc
)

# Link the Libraries
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        Qt6::Widgets
        Qt6::Gui
        Qt6::OpenGLWidgets
        Qt6::Core
        OpenGL::GL
)
