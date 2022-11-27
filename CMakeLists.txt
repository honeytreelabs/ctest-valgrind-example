cmake_policy(SET CMP0048 NEW)
project(leak)
cmake_minimum_required(VERSION 3.20)

enable_testing()

add_subdirectory(Catch2)
include(CTest)
include(Catch)

function(add_test_incl_memcheck name)
  add_executable(${name}_test ${name}_test.cpp)
  target_link_libraries(${name}_test PRIVATE
    Catch2::Catch2WithMain)

  add_test(NAME ${name}_test COMMAND ${name}_test)
  add_test(NAME ${name}_memchecked_test
    COMMAND valgrind
      --error-exitcode=1
      --tool=memcheck
      --leak-check=full
      --errors-for-leak-kinds=definite
      --show-leak-kinds=definite $<TARGET_FILE:${name}_test>
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
endfunction()

add_test_incl_memcheck(leak)
