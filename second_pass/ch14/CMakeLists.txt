cmake_minimum_required(VERSION 2.8.9)
project (el_prog_interview_ch1)

set(CMAKE_BUILD_TYPE Debug)

# Check for CppUTest and bail out if they don't have it
message("CPPUTEST_HOME:" $ENV{CPPUTEST_HOME})

if(DEFINED ENV{CPPUTEST_HOME})
    message("Using CppUTest found in $ENV{CPPUTEST_HOME}")
else()
    message("CPPUTEST_HOME is not set; You must tell CMake where to find CppUTest")
    return()
endif()

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)

# The version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib)

#es1
set (sources1 es1.cpp)
set (testSources1 test1.cpp)
add_executable(utest1 test.cpp ${testSources1} ${sources1})
target_link_libraries(utest1 CppUTest)

#es2
set (sources2 es2.cpp)
set (testSources2 test2.cpp)
add_executable(utest2 test.cpp ${testSources2} ${sources2})
target_link_libraries(utest2 CppUTest)

#es4
set (sources4 es4.cpp)
set (testSources4 test4.cpp)
add_executable(utest4 test.cpp ${testSources4} ${sources4})
target_link_libraries(utest4 CppUTest)




#es5
set (sources5 es5.cpp)
set (testSources5 test5.cpp)
add_executable(utest5 test.cpp ${testSources5} ${sources5})
target_link_libraries(utest5 CppUTest)


#es8
set (sources8 es8.cpp)
set (testSources8 test8.cpp)
add_executable(utest8 test.cpp ${testSources8} ${sources8})
target_link_libraries(utest8 CppUTest)

#es10
set (sources10 es10.cpp)
set (testSources10 test10.cpp)
add_executable(utest10 test.cpp ${testSources10} ${sources10})
target_link_libraries(utest10 CppUTest)

#es13
set (sources13 es13.cpp)
set (testSources13 test13.cpp)
add_executable(utest13 test.cpp ${testSources13} ${sources13})
target_link_libraries(utest13 CppUTest)

#es14
set (sources14 es14.cpp)
set (testSources14 test14.cpp)
add_executable(utest14 test.cpp ${testSources14} ${sources14})
target_link_libraries(utest14 CppUTest)

#es15
set (sources15 es15.cpp)
set (testSources15 test15.cpp)
add_executable(utest15 test.cpp ${testSources15} ${sources15})
target_link_libraries(utest15 CppUTest)


#es16
set (sources16 es16.cpp)
set (testSources16 test16.cpp)
add_executable(utest16 test.cpp ${testSources16} ${sources16})
target_link_libraries(utest16 CppUTest)





#interval_tree
set (sourceIntervalTree interval_tree.cpp)
set (testSourceIntervalTree testIntervalTree.cpp)
add_executable(utestItervalTree test.cpp ${testSourceIntervalTree}
                    ${sourceIntervalTree})
target_link_libraries(utestItervalTree CppUTest)
