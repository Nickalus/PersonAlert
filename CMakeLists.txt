CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

PROJECT(PersonAlert)

ADD_DEFINITIONS(-std=c++11)

SET(CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Gui)
FIND_PACKAGE(Qt5Core)
FIND_PACKAGE(PkgConfig)

#Find GStreamer
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0 gstreamer-bad-base-1.0 gstreamer-bad-video-1.0 )

INCLUDE_DIRECTORIES(${GSTREAMER_INCLUDE_DIRS})

# Sources
SET(SRC main.cpp MainWindow.cpp Pipeline.cpp)

SET(HEADERS MainWindow.hpp Pipeline.hpp)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC} ${HEADERS})
          
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets ${GSTREAMER_LIBRARIES})
