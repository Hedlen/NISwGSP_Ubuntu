cmake_minimum_required(VERSION 2.8)

PROJECT(NISwGSP)

FIND_PACKAGE(OpenMP REQUIRED)

#eigen
FIND_PACKAGE(Eigen3 REQUIRED)
include_directories(${EIGEN_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -DEIGEN_DONT_PARALLELIZE -std=c++11")


#opencv

set(OpenCV_DIR "/usr/local/opencv-3.0.0/share/OpenCV")
find_package(OpenCV REQUIRED)	
include_directories(${OpenCV_INCLUDE_DIRS})


##vlfeat
#set(VLFEAT_LIBRARY "/home/jiangting/dyp/re/wood/NISwGSP/UglyMan_NISwGSP_Stitching/UglyMan_NISwGSP_Stitching/vlfeat-0.9.20/bin/glnxa64")
#FIND_LIBRARY(VLFEAT_LIBRARY libvl)

aux_source_directory(./Debugger DEBUGGER_SRC)
aux_source_directory(./Feature FEATURE_SRC)
aux_source_directory(./Mesh MESH_SRC)
aux_source_directory(./Stitching STITCHING_SRC)
aux_source_directory(./Util UTIL_SRC)

add_executable(NISwGSP Configure.h main.cpp ${DEBUGGER_SRC} ${FEATURE_SRC} ${MESH_SRC} ${STITCHING_SRC} ${UTIL_SRC})
target_link_libraries(NISwGSP ${OpenCV_LIBS} "/home/jiangting/dyp/re/wood/NISwGSP/UglyMan_NISwGSP_Stitching/UglyMan_NISwGSP_Stitching/vlfeat-0.9.20/bin/glnxa64/libvl.so" "/home/jiangting/anaconda3/lib/libQt5Core.so.5")
