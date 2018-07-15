cmake_minimum_required(VERSION 3.5)

project(DoubleDispatch VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

# Manage dependencies

enable_testing()

# Finding Threads libs
find_package(Threads REQUIRED)

# Setting up Conan
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
    message(STATUS "Configuring dependencies with conan")
    execute_process(COMMAND conan install ${CMAKE_CURRENT_LIST_DIR} --build missing)
endif()

# Setting output directory to bin
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include(CTest)

set(SRC_LIST
    "src/DBConnection.hpp"
    "src/DBConnection.cpp"
    "src/DBConnection2.hpp"
    "src/DBConnection2.cpp"
    "src/ConnectionDispatcher.hpp"
    "src/ConnectionDispatcher.cpp"
    "src/DBConnection3.hpp"
    "src/DBConnection3.cpp"
    "src/DBConnection3Caster.hpp"
    "src/DBConnection4.hpp"
    "src/DBConnection4.cpp")

add_executable(testrunner
    "${SRC_LIST}"
    "test/ConnectionTest.cpp"
    "test/ConnectionTest2.cpp"
    "test/ConnectionTest3.cpp"
    "test/ConnectionTest4.cpp")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_include_directories(testrunner PRIVATE src test)

target_compile_options(testrunner PRIVATE -Wextra -pedantic)

target_link_libraries(testrunner PRIVATE ${CONAN_LIBS} ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME AllTests COMMAND testrunner)
