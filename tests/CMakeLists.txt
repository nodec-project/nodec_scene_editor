include(FetchContent)

function(add_target_if_missing TARGET GIT_REPOSITORY GIT_TAG)
    if(TARGET ${TARGET})
        return()
    endif()

    message("${TARGET} not found. Fetch the contents")
    FetchContent_Declare(
        ${TARGET}
        GIT_REPOSITORY ${GIT_REPOSITORY}
        GIT_TAG ${GIT_TAG}
        GIT_SHALLOW 1
    )
    FetchContent_MakeAvailable(${TARGET})

    # FetchContent_GetProperties(${TARGET})
    # if(NOT ${TARGET}_POPULATED)
    #     message("${TARGET} Populating")
    #     FetchContent_Populate(${TARGET})
    #     add_subdirectory(${${TARGET}_SOURCE_DIR} ${${TARGET}_BINARY_DIR})
    # endif()
endfunction(add_target_if_missing)

add_target_if_missing(nodec https://github.com/nodec-project/nodec.git main)
add_target_if_missing(imessentials https://github.com/nodec-project/imessentials.git main)
add_target_if_missing(imgui https://github.com/nodec-project/imgui.git main)

function(add_basic_test TARGET TEST_SOURCES)
    add_executable(${TARGET} ${TEST_SOURCES})
    target_link_libraries(${TARGET} nodec imessentials)
    target_include_directories(${TARGET} PRIVATE ${nodec_SOURCE_DIR}/tests/common)

    add_test(NAME ${TARGET} COMMAND ${TARGET})
endfunction(add_basic_test)

add_basic_test(component_editor component_editor.cpp)
