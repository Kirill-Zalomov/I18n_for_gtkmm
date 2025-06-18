cmake_minimum_required(VERSION 3.10)
project(i18n_lib_for_gtkmm)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(VERSION_GLIBMM "2.68")
set(VERSION_GIOBMM "2.68")


find_package(PkgConfig REQUIRED)
find_package(Catch2 REQUIRED)
pkg_check_modules(GLIBMM REQUIRED glibmm-${VERSION_GLIBMM} giomm-${VERSION_GIOBMM})


set(SOURCES
    src/translation_finder.cpp
)


set(SOURCES_OF_TESTS
    tests/translation_finder_tests.cpp
)


# add_executable(app ${SOURCES})
# target_include_directories(app PRIVATE
#     "./"
#     "./inc/"
#     ${GLIBMM_INCLUDE_DIRS}
# )
# target_link_libraries(app PRIVATE
#     ${GLIBMM_LIBRARIES}
# )


add_executable(tests ${SOURCES} ${SOURCES_OF_TESTS})
target_include_directories(tests PRIVATE
    "./"
    "./inc/"
    ${GLIBMM_INCLUDE_DIRS}
)
target_link_libraries(tests PRIVATE
    Catch2::Catch2WithMain
    ${GLIBMM_LIBRARIES}
)
enable_testing()
add_test(NAME tests COMMAND tests)
