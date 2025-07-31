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
set_tests_properties(no_dep_test PROPERTIES PASS_REGULAR_EXPRESSION "42")

add_test(NAME with_dep_test COMMAND with_dep)
set_tests_properties(with_dep_test PROPERTIES WILL_FAIL TRUE)
