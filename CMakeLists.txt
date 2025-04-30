cmake_minimum_required(VERSION 3.10)

set(entity_craft_qt_project_name EntityCraft_Qt)
option(ENTITY_CRAFT_QT_EXAMPLE "Add EntityCraft_Qt examples file as executable (on|off)" OFF )

project(${entity_craft_qt_project_name} LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core REQUIRED)

file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

if(NOT TARGET EntityCraft)
    add_subdirectory(include/external/EntityCraft)
endif()

if(NOT TARGET ReflectionApi_Qt)
    add_subdirectory(include/external/ReflectionApi_Qt)
endif()

add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        OUTPUT_NAME ${PROJECT_NAME}
)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt5::Core
        EntityCraft
        ReflectionApi_Qt
)

install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

install(DIRECTORY include
        DESTINATION include
)

if(${ENTITY_CRAFT_QT_EXAMPLE})
    add_subdirectory(example)
endif ()