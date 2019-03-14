# CMake Version 
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

# Project Name
PROJECT(VideoPlayer)

#
# Configuration
#
# SET(CMAKE_VERBOSE_MAKEFILE ON)
#

# cmake -DCMAKE_TOOLCHAIN_FILE=toolchain.arm.cmake

#
if ("${build}" MATCHES "debug")
 SET (CMAKE_BUILD_TYPE "debug")
else ("${build}" MATCHES "debug")
 SET (CMAKE_BUILD_TYPE "release")
endif ("${build}" MATCHES "debug")

#
# Add Compiler Option and Macro
#
ADD_DEFINITIONS(-DCALIB_CFG_BUILD_MODE="${CMAKE_BUILD_TYPE}")

# Set Build Directories
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

SET(LUNA_SW_PLATFORM ${CMAKE_CURRENT_SOURCE_DIR}/dependency/Luna)

include_directories(
	./ 
	./dependency/Luna/src/Library/ccCore/include
	./dependency/Luna/src/Library/ccNetwork/include
	./dependency/Luna/src/Library/ccWebServer/include
	./dependency/Luna/src/FossLibrary/ccJsonParser/include
	./dependency/Luna/src/FossLibrary/ccWebsocketClient/include
	./dependency/Luna/src/ThirdPartyLibrary/ccMongooseServer/include)

###########
# OpenCV
###########
find_package( OpenCV REQUIRED )

if (NOT OpenCV_FOUND)
	message(STATUS "OpenCV not found")
	set(USE_OPENCV OFF)
else()
	message(STATUS "OpenCV found")

	add_compile_definitions(OPENCV)
	include_directories( ${OpenCV_INCLUDE_DIRS} )
endif()

#
# Check OS and Processor Information 
#
SET(CMAKE_CXX_FLAGS "-std=c++1z")
ADD_DEFINITIONS(-Wall -DCALIB_CFG_OS="${CMAKE_SYSTEM_NAME}" -DCALIB_CFG_CPU="${CMAKE_SYSTEM_PROCESSOR}")

#
# Make Libraries
#
ADD_SUBDIRECTORY(dependency/Luna)

file(GLOB SRC_FILES 
  src/Player/*.cpp
  src/WebServer/*.cpp
)

#
# Make Applications
#
add_executable (VideoPlayer
    src/Player/VideoPlayer.cpp
)

TARGET_LINK_LIBRARIES(VideoPlayer
 ${OpenCV_LIBS}
	ccMongooseServer
	ccWebsocketClient
	ccJsonParser
	ccWebServer
	ccNetwork
	ccCore
	pthread
)
