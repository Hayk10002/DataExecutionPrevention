cmake_minimum_required(VERSION 3.10)

project(DataExecutionPrevention)

add_executable(no_dep main.cpp)
set_property(TARGET no_dep PROPERTY CXX_STANDARD 23)
target_compile_options(no_dep PRIVATE -fno-pie)
target_link_options(no_dep PRIVATE -no-pie -z execstack)

add_executable(with_dep main.cpp)
set_property(TARGET with_dep PROPERTY CXX_STANDARD 23)

enable_testing()

add_test(NAME no_dep_test COMMAND no_dep)

add_test(NAME with_dep_test COMMAND ${CMAKE_SOURCE_DIR}/signal_pass_wrapper.sh $<TARGET_FILE:with_dep>)
