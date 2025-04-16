cmake_minimum_required(VERSION 3.28)

project(EntityCraft_Qt LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core REQUIRED)

if(NOT TARGET EntityCraft)
    add_subdirectory(include/external/EntityCraft)
endif()

file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt5::Core
        EntityCraft
)
