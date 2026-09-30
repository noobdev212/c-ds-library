project(test)

option(ENABLE_TEST_ARRAY "Enable Testing for ArrayList" ON)

if(ENABLE_TEST_ARRAY)
  add_executable(utest_array utest_array.c)
  target_link_libraries(utest_array PRIVATE cds-static)
  target_include_directories(utest_array PRIVATE global.h)
endif()

