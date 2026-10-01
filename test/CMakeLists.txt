project(test)

option(ENABLE_TEST_ARRAY "Enable Testing for ArrayList" ON)
option(ENABLE_TEST_LIST "Enable Testing for LinkedList" ON)
option(ENABLE_TEST_STACK "Enable Testing for Stack" ON)

if(ENABLE_TEST_ARRAY)
  add_executable(utest_array utest_array.c global.h)
  target_link_libraries(utest_array PRIVATE cds-static)
endif()

if(ENABLE_TEST_LIST)
  add_executable(utest_list utest_list.c global.h)
  target_link_libraries(utest_list PRIVATE cds-static)
endif()

if(ENABLE_TEST_STACK)
  add_executable(utest_stack utest_stack.c global.h)
  target_link_libraries(utest_stack PRIVATE cds-static)
endif()
