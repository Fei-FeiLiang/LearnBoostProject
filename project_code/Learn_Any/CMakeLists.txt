cmake_minimum_required (VERSION 3.10)


get_filename_component(DIRECTORY_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)    #获取文件夹名称

project(${DIRECTORY_NAME})

if(NOT ROOTPATH)
  file(TO_CMAKE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../" ROOTPATH)
endif()

#set_property(TARGET ${TARGET} PROPERTY FOLDER "${TARGET}")


include(${ROOTPATH}/cmake/addsubdirectory.cmake)