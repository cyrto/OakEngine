cmake_minimum_required (VERSION 3.8)



project ("Engine")

find_package ( OpenGL REQUIRED )

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

link_directories(${SDL2_LIBRARY})

set ( PRJ_INC_LIST )
set ( PRJ_SRC_LIST )
set ( PRJ_LIBRARIES )
set ( PRJ_INCLUDE_DIRS )


set ( GLFW_HOME "E:/Program/cpp/glfw-3.3.5.bin.WIN64" )
set ( GLFW_INC "${GLFW_HOME}/include" ) 
set ( GLFW_LIB "${GLFW_HOME}/lib-vc2019/glfw3dll.lib" )


file ( GLOB root_header_files 
"${CMAKE_CURRENT_SOURCE_DIR}/*.h"  
"${CMAKE_CURRENT_SOURCE_DIR}/**/*.h"
"${CMAKE_CURRENT_SOURCE_DIR}/**/**/*.h"
)
file ( GLOB root_src_files 
"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" 
"${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/**/**/*.cpp"
)



list ( APPEND PRJ_INCLUDE_DIRS . )
list ( APPEND PRJ_INCLUDE_DIRS ${GLFW_INC} )
list ( APPEND PRJ_INCLUDE_DIRS ${SDL2_INCLUDE_DIR} )
list ( APPEND PRJ_INCLUDE_DIRS ${SDL2_IMAGE_INCLUDE_DIRS} )

list ( APPEND PRJ_INC_LIST ${root_header_files} )

list ( APPEND PRJ_SRC_LIST ${root_src_files} )

list ( APPEND PRJ_LIBRARIES ${GLFW_LIB} )
list ( APPEND PRJ_LIBRARIES ${OPENGL_LIBRARIES} )
list ( APPEND PRJ_LIBRARIES ${SDL2_LIBRARY} )
list ( APPEND PRJ_LIBRARIES ${SDL2_IMAGE_LIBRARIES} )

file(COPY ${CMAKE_SOURCE_DIR}/Assets DESTINATION "${CMAKE_BINARY_DIR}/${PROJECT_NAME}")

add_executable ( ${PROJECT_NAME} ${PRJ_SRC_LIST} ${PRJ_INC_LIST})




target_include_directories ( ${PROJECT_NAME}
	PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_LIBRARIES}
)



MESSAGE( STATUS "root_header_files = ${CMAKE_BINARY_DIR}")
MESSAGE( STATUS "root_header_files = ${root_header_files}")
MESSAGE( STATUS "root_src_files = ${root_src_files}")
MESSAGE( STATUS "PRJ_INCLUDE_DIRS = ${PRJ_INCLUDE_DIRS}")
MESSAGE( STATUS "PRJ_LIBRARIES = ${PRJ_LIBRARIES}")