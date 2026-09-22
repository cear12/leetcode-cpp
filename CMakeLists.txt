cmake_minimum_required(VERSION 3.16)
project(leetcode_solutions_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# GCC/Clang spelling of the warning flags; MSVC rejects -Wextra outright
# (error D8021: invalid numeric argument), which is what broke the Windows job.
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include(CTest)
enable_testing()

# Every solution file under problems/<difficulty>/<problem>/ is a
# self-contained translation unit with its own main() (see
# problems/common/leetcode_common.h for the shared prelude it relies on).
# Rather than hand-listing 80+ targets, each file becomes its own
# executable and its own CTest case: the executable's exit code is 0 only
# if every [PASS]/[FAIL] check inside its main() passed.
file(GLOB_RECURSE SOLUTION_SOURCES CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/problems/*/*/*.cpp")

foreach(SRC ${SOLUTION_SOURCES})
    file(RELATIVE_PATH REL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/problems" "${SRC}")
    # e.g. medium/3-sum/optimal.cpp -> medium__3-sum__optimal
    string(REPLACE "/" ";" PATH_PARTS "${REL_PATH}")
    list(GET PATH_PARTS 0 DIFFICULTY)
    list(GET PATH_PARTS 1 PROBLEM)
    list(GET PATH_PARTS 2 VARIANT_FILE)
    get_filename_component(VARIANT "${VARIANT_FILE}" NAME_WE)
    set(TARGET_NAME "${DIFFICULTY}__${PROBLEM}__${VARIANT}")

    add_executable(${TARGET_NAME} "${SRC}")
    target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/problems/common")
    add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
endforeach()

list(LENGTH SOLUTION_SOURCES NUM_SOLUTIONS)
message(STATUS "leetcode-cpp: configured ${NUM_SOLUTIONS} solution executables/tests")
