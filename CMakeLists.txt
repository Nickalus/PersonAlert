CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

PROJECT(PersonAlert)

SET(CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Core)

#Find my libraries
FIND_LIBRARY(GST1 NAMES gstreamer-1.0)
FIND_LIBRARY(GOBJ2 NAMES gobject-2.0)
FIND_LIBRARY(GLIB2 NAMES glib-2.0)

INCLUDE_DIRECTORIES(/usr/include/glib-2.0/)
INCLUDE_DIRECTORIES(/usr/include/gstreamer-1.0)
INCLUDE_DIRECTORIES(/usr/lib64/glib-2.0/include/)
INCLUDE_DIRECTORIES(/usr/lib64/gstreamer-1.0/include/)

# Sources
SET(SRC main.cpp
        MainWindow.cpp)

SET(HEADERS MainWindow.hpp
            Pipeline.hpp)
            
ADD_EXECUTABLE(${PROJECT_NAME} ${SRC} ${HEADERS})
          
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Core Qt5::Widgets ${GST1} ${GOBJ2} ${GLIB2})
