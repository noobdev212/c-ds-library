cmake_minimum_required(VERSION 3.14...4.4)

project(CDS LANGUAGES C VERSION "1.0")

# do not dereference variables or interpret keywords that 
# have been quoted or bracketed
if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

# recognize numbers and boolean constants without dereferencing 
# variables with such names
if(POLICY CMP0012)
  cmake_policy(SET CMP0012 NEW)
endif()

# behavior is to interpret the IN_LIST operator
if (POLICY CMP0057)
  cmake_policy(SET CMP0057 NEW)
endif()

if(NOT CMAKE_BUILD_TYPE)
  set(cmake_build_type_undefined YES)
endif()

# Enforce behavior if set as main project
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  message(VERBOSE "CDS is set to main project")
  set(CDS_MAINPROJ ON)
else()
  set(CDS_MAINPROJ OFF)
endif()

# Set to RelWithDebInfo by default for main project
if(CDS_MAINPROJ)
  get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
  if(DEFINED CMAKE_CONFIGURATION_TYPES AND "RelWithDebInfo" IN_LIST CMAKE_CONFIGURATION_TYPES)
    list(REMOVE_ITEM CMAKE_CONFIGURATION_TYPES "RelWithDebInfo")
    list(INSERT CMAKE_CONFIGURATION_TYPES 0 "RelWithDebInfo")
    set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING "CMake configuration types" FORCE)
  else()
    if(cmake_build_type_undefined)
      set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "CMake build type" FORCE)
    endif()
  endif()
endif()

set(USE_GCC FALSE)
if(CMAKE_C_COMPILER_ID MATCHES "GNU")
  set(USE_GCC TRUE)
endif()

# GCC is the only currently supported compiler
if(NOT USE_GCC)
  message(FATAL_ERROR "GCC is stricly required")
endif()

include(CMakeDependentOption)
include(CheckCCompilerFlag)
option(CDS_TEST_LIBRARY "Build the CDS test library" ON)
cmake_dependent_option(CDS_TESTS "Build the test directory" "${CDS_MAINPROJ}" CDS_TEST_LIBRARY OFF)

add_library(cds-static STATIC)
target_sources(cds-static 
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/arraylist.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/operator.c"
)
target_include_directories(cds-static PUBLIC 
  ${PROJECT_SOURCE_DIR}/include
)

function(add_compiler_flag TARGET FLAG)
  check_c_compiler_flag("${FLAG}" HAS_OPTION)
  if(HAS_OPTION)
    target_compile_options(${TARGET} PRIVATE ${FLAG})
  endif()
endfunction()

add_compiler_flag(cds-static "-Wall")
add_compiler_flag(cds-static "-Wextra")
add_compiler_flag(cds-static "-Wno-unused-parameter")
add_compiler_flag(cds-static "-Wdouble-promotion")
add_compiler_flag(cds-static "-Wconversion")
add_compiler_flag(cds-static "-fsanitize=address")

check_c_compiler_flag("-g3" IS_AVAILABE_OPTION)
if (IS_AVAILABE_OPTION)
  target_compile_options(cds-static PRIVATE "-g3")
else()
  target_compile_options(cds-static PRIVATE "-g")
endif()


if(CDS_TESTS)
  message(VERBOSE "test is set to on")
  add_subdirectory(test)
endif()
