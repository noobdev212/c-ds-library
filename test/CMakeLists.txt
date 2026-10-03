project(test)

option(ENABLE_TEST_ARRAY "Enable Testing for ArrayList" ON)
option(ENABLE_TEST_LIST "Enable Testing for LinkedList" ON)
option(ENABLE_TEST_STACK "Enable Testing for Stack" ON)
option(ENABLE_TEST_QUEUE "Enable Testing for Queue" ON)
option(ENABLE_TEST_STRING "Enable Testing for String" ON)

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

if(ENABLE_TEST_QUEUE)
  add_executable(utest_queue utest_queue.c global.h)
  target_link_libraries(utest_queue PRIVATE cds-static)
endif()

if(ENABLE_TEST_STRING)
  add_executable(utest_string utest_string.c global.h)
  target_link_libraries(utest_string PRIVATE cds-static)
endif()
