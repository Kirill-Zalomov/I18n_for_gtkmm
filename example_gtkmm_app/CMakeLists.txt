cmake_minimum_required(VERSION 3.10)
project(gui_test)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(VERSION_GTKMM  "4.0")
set(VERSION_GLIBMM "2.68")
set(VERSION_GIOBMM "2.68")


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM  REQUIRED gtkmm-${VERSION_GTKMM})
pkg_check_modules(GLIBMM REQUIRED glibmm-${VERSION_GLIBMM} giomm-${VERSION_GIOBMM})


set(SOURCES
    src/main.cpp
    src/hello_world.cpp
)


add_executable(app ${SOURCES})
set_target_properties(app PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
target_include_directories(app PRIVATE
    "./"
    "./inc/"
    ${GTKMM_INCLUDE_DIRS}
    ${GLIBMM_INCLUDE_DIRS}
)
target_link_libraries(app PRIVATE
    ${GTKMM_LIBRARIES}
    ${GLIBMM_LIBRARIES}
)
