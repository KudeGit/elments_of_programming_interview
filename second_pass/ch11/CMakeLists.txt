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

IF(CMAKE_BUILD_TYPE MATCHES Debug)
      message("Debug build.")
ENDIF()

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

#es3
set (sources3 es3.cpp)
set (testSources3 test3.cpp)
add_executable(utest3 test.cpp ${testSources3} ${sources3})
target_link_libraries(utest3 CppUTest)

#es4
set (sources4 es4.cpp)
set (testSources4 test4.cpp)
add_executable(utest4 test.cpp ${testSources4} ${sources4})
target_link_libraries(utest4 CppUTest)

#es7
set (sources7 es7.cpp)
set (testSources7 test7.cpp)
add_executable(utest7 test.cpp ${testSources7} ${sources7})
target_link_libraries(utest7 CppUTest)

#es8
set (sources8 es8.cpp)
set (testSources8 test8.cpp)
add_executable(utest8 test.cpp ${testSources8} ${sources8})
target_link_libraries(utest8 CppUTest)


