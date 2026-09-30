project(test)

option(ENABLE_TEST_ARRAY "Enable Testing for ArrayList" ON)

if(ENABLE_TEST_ARRAY)
  add_executable(unit_array unit_array.c)
  target_link_libraries(unit_array PRIVATE cds-static)
endif()

