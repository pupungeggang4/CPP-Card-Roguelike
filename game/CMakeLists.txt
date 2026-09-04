cmake_minimum_required(VERSION 3.20)
project(cmake_example LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

if(EMSCRIPTEN)
    set(PLATFORM "Web" CACHE STRING "raylib platform")
else()
    set(PLATFORM "Desktop" CACHE STRING "raylib platform")
endif()

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib
    GIT_TAG master
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(PLATFORM ${PLATFORM} CACHE STRING "" FORCE)
FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.c"
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

file(COPY "${CMAKE_SOURCE_DIR}/asset" DESTINATION "${CMAKE_BINARY_DIR}/bin")

add_executable(main src/main.cpp ${ALL_SOURCES})
target_include_directories(main PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(main raylib)

if(EMSCRIPTEN)
    set_target_properties(main PROPERTIES OUTPUT_NAME "index" SUFFIX ".html" RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
    target_compile_options(main PRIVATE -Os)
    target_link_libraries(main idbfs.js)
    target_link_options(main PRIVATE 
        "-Os"
        "-sUSE_GLFW=3"
        "--preload-file=${CMAKE_SOURCE_DIR}/asset@asset"
    )
    target_compile_definitions(main PRIVATE PLATFORM_WEB)
endif()
