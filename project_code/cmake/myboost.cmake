
if(NOT LIB3RDPATH)
   file(TO_CMAKE_PATH "${ROOTPATH}/3rd" LIB3RDPATH)
endif()


if(NOT MYBOOSTINCLUDEPATH)
   file(TO_CMAKE_PATH "D:/myProject/opensource/boost_1_77_0/build/include/boost-1_77" MYBOOSTINCLUDEPATH)
endif()

if(NOT MYBOOSTLIBPATH)
   file(TO_CMAKE_PATH "D:/myProject/opensource/boost_1_77_0/build/lib" MYBOOSTLIBPATH)
endif()



target_include_directories(${TARGET} PRIVATE ${MYBOOSTINCLUDEPATH})
#target_include_directories(${TARGET} PRIVATE ${LIB3RDPATH}/libzmq-4.3.4/include)

#target_link_directories(${TARGET} PRIVATE $<$<CONFIG:Debug>:${LIB3RDPATH}/lib/debug})
#target_link_directories(${TARGET} PRIVATE $<$<CONFIG:Release>:${LIB3RDPATH}/lib/release>)

target_link_directories(${TARGET} PRIVATE $<$<CONFIG:Release>:${MYBOOSTINCLUDEPATH}>)
target_link_directories(${TARGET} PRIVATE $<$<CONFIG:Release>:${MYBOOSTINCLUDEPATH}>)

#target_link_libraries($<$<CONFIG:Debug>:libzmq-v142-mt-s-4_3_4_d>)
#target_link_libraries(${TARGET} PRIVATE $<$<CONFIG:Release>:libzmq-v142-mt-s-4_3_4>)


#target_link_libraries(${TARGET} PRIVATE $<$<CONFIG:Release>:wsock32>)
#target_link_libraries(${TARGET} PRIVATE $<$<CONFIG:Release>:ws2_32>)
#target_link_libraries(${TARGET} PRIVATE $<$<CONFIG:Release>:Iphlpapi>)