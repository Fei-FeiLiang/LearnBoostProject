cmake_minimum_required (VERSION 3.10)

get_filename_component(TARGET ${CMAKE_CURRENT_SOURCE_DIR} NAME)

get_filename_component(SECOND_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(SECOND_FOLDER ${SECOND_FOLDER_ABSOLUTE} NAME)

project(${TARGET})

#静态库
#add_compile_definitions(ZMQ_STATIC)

if(NOT ROOTPATH)
  file(TO_CMAKE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../" ROOTPATH)
endif()
 
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${ROOTPATH}/bin/debug)   
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${ROOTPATH}/bin/release)
 
#file(GLOB SRC_FILES "./src/*.cpp")
#file(GLOB HEAD_FILES "./src/*.h")
#file(GLOB MOC_FILES "mocs_*.cpp")

#源文件目录
file(TO_CMAKE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" SOURCEPATH)

file(GLOB_RECURSE FORMS_SOURCE "${SOURCEPATH}/*.ui")
file(GLOB_RECURSE HEADERS_SOURCE "${SOURCEPATH}/*.h")
file(GLOB_RECURSE CPP_SOURCE "${SOURCEPATH}/*.cpp")
file(GLOB_RECURSE RES_SOURCE "${SOURCEPATH}/*.qrc"
                                "${SOURCEPATH}/*.rc")

#source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${HEAD_FILES})
#source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${SRC_FILES})
#add_executable(${PROJECT_NAME} ${HEAD_FILES} ${SRC_FILES} ${MOC_FILES})

include(${ROOTPATH}/cmake/app.cmake)
include(${ROOTPATH}/cmake/myboost.cmake)

set_property(TARGET ${TARGET} PROPERTY FOLDER "${SECOND_FOLDER}/${TARGET}")