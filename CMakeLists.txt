cmake_minimum_required(VERSION 3.5.0)
project(twitchcap)

find_package(
    Qt6
    COMPONENTS
        Network
        Widgets
    REQUIRED
)

set(CMAKE_AUTOMOC ON)
set(MOCUIC_DIR ${CMAKE_CURRENT_BINARY_DIR}/.mocuic)

add_executable(
    twitchcap
        src/tcconnection.cpp
        src/tcinfodialog.cpp
        src/tcmainwindow.cpp
        src/tcsettings.cpp
        src/twitchcap.cpp
        ${RCC_SOURCES}
)

set_target_properties(
    twitchcap
    PROPERTIES
        AUTOGEN_BUILD_DIR
            ${MOCUIC_DIR}
)

target_link_libraries(
    twitchcap
        Qt6::Network
        Qt6::Widgets
)
