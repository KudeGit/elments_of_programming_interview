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

#file(GLOB SOURCES "*.cpp")
#es1
set (sources1 es1.cpp)
set (testSources1 test1.cpp)
add_executable(utest1 test.cpp ${testSources1} ${sources1})
target_link_libraries(utest1 CppUTest)

#es2
set (sources2 es2.cpp)
set (testSources2 test2.cpp)
add_executable(utest2 test.cpp test_utilities.cpp ${testSources2} ${sources2})
target_link_libraries(utest2 CppUTest)

#es4
set (sources4 es4.cpp)
set (testSources4 test4.cpp)
add_executable(utest4 test.cpp test_utilities.cpp ${testSources4} ${sources4})
target_link_libraries(utest4 CppUTest)

#es5
set (sources5 es5.cpp)
set (testSources5 test5.cpp)
add_executable(utest5 test.cpp test_utilities.cpp ${testSources5} ${sources5})
target_link_libraries(utest5 CppUTest)

#es7
set (sources7 es7.cpp)
set (testSources7 test7.cpp)
add_executable(utest7 test.cpp test_utilities.cpp ${testSources7} ${sources7})
target_link_libraries(utest7 CppUTest)

#es8
set (sources8 es8.cpp)
set (testSources8 test8.cpp)
add_executable(utest8 test.cpp test_utilities.cpp ${testSources8} ${sources8})
target_link_libraries(utest8 CppUTest)

#es10
set (sources10 es10.cpp)
set (testSources10 test10.cpp)
add_executable(utest10 test.cpp test_utilities.cpp ${testSources10} ${sources10})
target_link_libraries(utest10 CppUTest)

#es11
set (sources11 es11.cpp)
set (testSources11 test11.cpp)
add_executable(utest11 test.cpp test_utilities.cpp ${testSources11} ${sources11})
target_link_libraries(utest11 CppUTest)

#es16
set (sources16 es16.cpp)
set (testSources16 test16.cpp)
add_executable(utest16 test.cpp test_utilities.cpp ${testSources16} ${sources16})
target_link_libraries(utest16 CppUTest)

#es18
set (sources18 es18.cpp)
set (testSources18 test18.cpp)
add_executable(utest18 test.cpp test_utilities.cpp ${testSources18} ${sources18})
target_link_libraries(utest18 CppUTest)
