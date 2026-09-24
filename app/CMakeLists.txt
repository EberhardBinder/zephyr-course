cmake_minimum_required(VERSION 3.20.0)

list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
find_package(Zephyr REQUIRED)
project(my_zephyr_app)

target_sources(app PRIVATE src/main.cpp)

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
target_include_directories(app PRIVATE include)

>>>>>>> eb7ae2e (Complete assignment work)
>>>>>>> cd9384b (Complete assignment work)
add_subdirectory(drivers/our_driver)
