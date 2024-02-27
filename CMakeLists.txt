project(twitchcap)
cmake_minimum_required(VERSION 3.5.0)

find_package(
    Qt5
    COMPONENTS
        Network
        Widgets
    REQUIRED
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(MOCUIC_DIR ${CMAKE_CURRENT_BINARY_DIR}/.mocuic)

qt5_add_resources(
    RCC_SOURCES
        src/resources.qrc
)

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
        Qt5::Network
        Qt5::Widgets
)
