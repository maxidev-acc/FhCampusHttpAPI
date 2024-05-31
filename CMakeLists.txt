cmake_minimum_required(VERSION 3.5.0)
project(FhCampusHttpAPI VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Gather all source files from the lib directory
file(GLOB_RECURSE LIB_FILES lib/*.cpp)


add_executable(FhCampusHttpAPIRuntime "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp" ${LIB_FILES})
add_executable(ServerAPI "${CMAKE_CURRENT_SOURCE_DIR}/src/server.cpp" ${LIB_FILES})
target_link_libraries(ServerAPI PRIVATE ws2_32)
target_include_directories(ServerAPI PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(FhCampusHttpAPIRuntime PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

# Set CPack project details
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


