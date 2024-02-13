qt5_add_resources(
    RCC_SOURCES
    resources.qrc
)

add_executable(
    twitchcap
        tcconnection.cpp
        tcinfodialog.cpp
        tcmainwindow.cpp
        tcsettings.cpp
        twitchcap.cpp
        ${RCC_SOURCES}
)

set_target_properties(
    twitchcap
    PROPERTIES
        AUTOGEN_BUILD_DIR
            ${MOCUIC_DIR}
        RUNTIME_OUTPUT_DIRECTORY
            ${TWITCHCAP_BINARY_DIR}
)

target_link_libraries(
    twitchcap
        Qt5::Network
        Qt5::Widgets
)
