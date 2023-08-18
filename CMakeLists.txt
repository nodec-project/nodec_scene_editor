cmake_minimum_required(VERSION 3.15)

project(nodec_scene_editor LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE include
)

target_link_libraries(${PROJECT_NAME}
    INTERFACE
    nodec imessentials nodec_scene
)

option(NODEC_SCENE_EDITOR_BUILD_TESTS "Enable bulding tests." OFF)

if(NODEC_SCENE_EDITOR_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()
