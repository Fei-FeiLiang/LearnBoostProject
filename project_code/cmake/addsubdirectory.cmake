

#message(${DIRECTORY_NAME})


get_filename_component(VAR_PARENT ${CMAKE_CURRENT_SOURCE_DIR}/.. ABSOLUTE)

#message(${VAR_PARENT})

if(NOT ROOTPATH)
  file(TO_CMAKE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../" ROOTPATH)
endif()

file(GLOB children LIST_DIRECORIES true "${CMAKE_CURRENT_SOURCE_DIR}/*")
set(dirlist "")
foreach(child ${children})
    if(IS_DIRECTORY ${child})
	    get_filename_component(subdirectory ${child} NAME)
		if(EXISTS "${child}/CMakeLists.txt")
		    add_subdirectory(${subdirectory})
		endif()
	endif()
endforeach()