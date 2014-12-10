option(ENABLE_GCOV "Enable gcov, Linux builds only." OFF)
option(BUILD_M32 "Enable gcov, Linux builds only." OFF)

project(PrjWithCi)
cmake_minimum_required(VERSION 2.6)

message(STATUS "CMAKE_C_FLAGS default:" ${CMAKE_C_FLAGS})
message(STATUS "CMAKE_C_FLAGS_DEBUG default:" ${CMAKE_C_FLAGS_DEBUG})
message(STATUS "CMAKE_C_FLAGS_RELEASE default:" ${CMAKE_C_FLAGS_RELEASE})

message(STATUS "CMAKE_CXX_FLAGS default:" ${CMAKE_CXX_FLAGS})
message(STATUS "CMAKE_CXX_FLAGS_DEBUG default:" ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "CMAKE_CXX_FLAGS_RELEASE default:" ${CMAKE_CXX_FLAGS_RELEASE})

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -O2 -Wall -Wno-deprecated -D__STDC_LIMIT_MACROS")

#add_definitions(-std=c++0x)

#if (ENABLE_GCOV)
#	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
#	set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
#	set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage -lgcov")
#endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(Boost_DEBUG 1)
find_package(Boost 1.53.0 REQUIRED COMPONENTS system filesystem program_options)
include_directories(${Boost_INCLUDE_DIRS})
message(STATUS "Boost_SYSTEM_LIBRARY:" ${Boost_SYSTEM_LIBRARY})
message(STATUS "Boost_FILESYSTEM_LIBRARY:" ${Boost_FILESYSTEM_LIBRARY})
message(STATUS "Boost_PROGRAM_OPTIONS_LIBRARY:" ${Boost_PROGRAM_OPTIONS_LIBRARY})

if (ENABLE_GCOV)
	add_subdirectory(3rd/gtest-1.7.0)
	#enable_testing()
	include_directories(${PROJECT_SOURCE_DIR}/3rd/gtest-1.7.0/include)
	add_subdirectory(3rd/gentle-exit)
endif()

include_directories("${PROJECT_SOURCE_DIR}/3rd/avboost/include")
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/src")
if(BUILD_M32)
	message(STATUS "Target: 32")
    #link_directories("${PROJECT_SOURCE_DIR}/lib")
else()
	message(STATUS "Target: 64")
    #link_directories("${PROJECT_SOURCE_DIR}/lib64")
endif()

add_subdirectory(src)
if (ENABLE_GCOV)
	add_subdirectory(ut)
endif()

#set(sources 
#   gtest_main.cpp 
#   example_one.Test.cpp 
#   example_two.Test.cpp)
#add_executable(test ${sources})
#target_link_libraries(test gtest)
#target_link_libraries(test tbsys tbnet common)

#执行系统命令
#execute_process(
#	COMMAND mkdir ${PROJECT_SOURCE_DIR}/build/ylw
#	COMMAND cp ${PROJECT_SOURCE_DIR}/CMakeLists.txt ${PROJECT_SOURCE_DIR}/build/ylw
#	)

