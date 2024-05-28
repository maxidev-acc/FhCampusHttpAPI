cmake_minimum_required(VERSION 3.5.0)
project(FhCampusHttpAPI VERSION 0.1.0 LANGUAGES C CXX)
include(CTest)
enable_testing()
file(GLOB_RECURSE LIB_FILES lib/*.cpp)
add_executable(FhCampusHttpAPIRuntime "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp" ${LIB_FILES})
include_directories(FhCampusHttpAPI "${CMAKE_CURRENT_SOURCE_DIR}/include/")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


