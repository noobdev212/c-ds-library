project(test)

option(ENABLE_TEST_ARRAY "Enable Testing for ArrayList" ON)

if(ENABLE_TEST_ARRAY)
  add_executable(utest_array utest_array.c)
  target_link_libraries(utest_array PRIVATE cds-static)
endif()

