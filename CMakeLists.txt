cmake_minimum_required(VERSION 3.16)

project(VideoDatabase VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(nlohmann_json CONFIG REQUIRED)

file(GLOB_RECURSE PROJECT_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.ui"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.qrc"
)

add_executable(VideoDatabase
    ${PROJECT_SOURCES}
)

target_link_libraries(
    VideoDatabase
    PRIVATE
        Qt6::Widgets
        nlohmann_json::nlohmann_json
)

set_target_properties(VideoDatabase PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)