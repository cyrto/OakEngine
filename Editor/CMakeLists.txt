# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("Editor")

find_package ( OpenGL REQUIRED )

set ( PRJ_INC_LIST )
set ( PRJ_SRC_LIST )
set ( PRJ_LIBRARIES )
set ( PRJ_INCLUDE_DIRS )

set ( GLFW_HOME "E:/Program/cpp/glfw-3.3.5.bin.WIN64" )
#set ( GLAD_HOME "d:/software/glad" )
set ( IMGUI_HOME "E:/Program/cpp/imgui" )

set ( GLFW_INC "${GLFW_HOME}/include" )
set ( GLFW_LIB "${GLFW_HOME}/lib-vc2019/glfw3dll.lib" )

set ( IMGUI_INC "${IMGUI_HOME}" )
set ( IMGUI_SRC "${IMGUI_HOME}" )
set ( IMGUI_BACKEND "${IMGUI_HOME}/backends" )

file ( GLOB root_header_files "${CMAKE_CURRENT_SOURCE_DIR}/*.h"  "${CMAKE_CURRENT_SOURCE_DIR}/**/*.h")
file ( GLOB root_src_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp")


MESSAGE( STATUS "root_header_files = ${root_header_files}")
MESSAGE( STATUS "root_src_files = ${root_src_files}")


file ( GLOB imgui_header_files "${IMGUI_INC}/*.h" )
file ( GLOB imgui_src_files "${IMGUI_SRC}/*.cpp" )

list ( APPEND imgui_header_files "${IMGUI_BACKEND}/imgui_impl_opengl3_loader.h" )
list ( APPEND imgui_header_files "${IMGUI_BACKEND}/imgui_impl_opengl3.h" )
list ( APPEND imgui_header_files "${IMGUI_BACKEND}/imgui_impl_glfw.h" )

 list ( APPEND imgui_src_files "${IMGUI_BACKEND}/imgui_impl_opengl2.cpp" )
 list ( APPEND imgui_src_files "${IMGUI_BACKEND}/imgui_impl_glfw.cpp" )

list ( APPEND PRJ_INCLUDE_DIRS . )
list ( APPEND PRJ_INCLUDE_DIRS ${GLFW_INC} )
list ( APPEND PRJ_INCLUDE_DIRS ${IMGUI_INC} )
list ( APPEND PRJ_INCLUDE_DIRS ${IMGUI_BACKEND} )

list ( APPEND PRJ_INC_LIST ${root_header_files} )
list ( APPEND PRJ_INC_LIST ${imgui_header_files} )

list ( APPEND PRJ_SRC_LIST ${root_src_files} )
list ( APPEND PRJ_SRC_LIST ${imgui_src_files} )

list ( APPEND PRJ_LIBRARIES ${GLFW_LIB} )
list ( APPEND PRJ_LIBRARIES ${OPENGL_LIBRARIES} )

add_executable ( ${PROJECT_NAME} ${PRJ_SRC_LIST} ${PRJ_INC_LIST})

target_include_directories ( ${PROJECT_NAME}
	PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_LIBRARIES}
)
