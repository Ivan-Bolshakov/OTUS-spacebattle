cmake_minimum_required(VERSION 3.2)

project(cmake VERSION 0.0.1)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(spacebattle_main src/main.cpp)

add_subdirectory(gtest)
include_directories(gtest/googletest/include)
include_directories(src)

add_executable(test_spacebattle test/move_test.cpp test/rotate_test.cpp test/fuel_test.cpp test/macro_test.cpp)

set_target_properties(spacebattle_main test_spacebattle PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(test_spacebattle PRIVATE gtest gmock_main)

install(TARGETS spacebattle_main RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(test_spacebattle_tests test_spacebattle)
