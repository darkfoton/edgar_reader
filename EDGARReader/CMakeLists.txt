cmake_minimum_required(VERSION 3.16)

project(EDGARReader VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(EDGARReader
    main.cpp
)

qt_add_qml_module(EDGARReader
    URI EDGARReader
    VERSION 1.0
    QML_FILES CoreView.qml
    SOURCES coreviewmodel.h coreviewmodel.cpp
    SOURCES applicationpropertiesviewmodel.h applicationpropertiesviewmodel.cpp
    QML_FILES AppPropertiesView.qml
    SOURCES downloadviewmodel.h downloadviewmodel.cpp
    SOURCES downloadslistmodel.h downloadslistmodel.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(EDGARReader PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.EDGARReader
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(EDGARReader
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS EDGARReader
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
