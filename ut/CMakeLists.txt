if (ENABLE_GCOV)
    #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
    #set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
    #set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage -lgcov")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --coverage")
endif()

macro (build_and_run arg)
	add_executable(${arg} ${arg}.cpp)
	add_test(${arg} ${arg})
endmacro ()

#build_and_run(gtest_main)
set(sources 
   gtest_main.cpp 
   sample.Test.cpp
   fixture.Test.cpp
   )
add_executable(ut_gtest ${sources})
target_link_libraries(ut_gtest gtest)
target_link_libraries(ut_gtest dir_srcs)
target_link_libraries(ut_gtest gentle-exit)

