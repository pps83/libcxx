function(find_compiler_rt_library name dest)
  if (NOT DEFINED LIBCXX_COMPILE_FLAGS)
    message(FATAL_ERROR "LIBCXX_COMPILE_FLAGS must be defined when using this function")
  endif()
  set(dest "" PARENT_SCOPE)
  set(CLANG_COMMAND ${CMAKE_CXX_COMPILER} ${LIBCXX_COMPILE_FLAGS}
      "--rtlib=compiler-rt" "--print-libgcc-file-name")
  execute_process(
      COMMAND ${CLANG_COMMAND}
      RESULT_VARIABLE HAD_ERROR
      OUTPUT_VARIABLE LIBRARY_FILE
  )
  string(STRIP "${LIBRARY_FILE}" LIBRARY_FILE)
  string(REPLACE "builtins" "${name}" LIBRARY_FILE "${LIBRARY_FILE}")
  if (NOT HAD_ERROR AND EXISTS "${LIBRARY_FILE}")
    message(STATUS "Found compiler-rt library: ${LIBRARY_FILE}")
    set(${dest} "${LIBRARY_FILE}" PARENT_SCOPE)
  else()
    message(STATUS "Failed to find compiler-rt library")
  endif()
endfunction()

function(find_compiler_rt_dir dest)
  if (NOT DEFINED LIBCXX_COMPILE_FLAGS)
    message(FATAL_ERROR "LIBCXX_COMPILE_FLAGS must be defined when using this function")
  endif()
  set(dest "" PARENT_SCOPE)
  if (APPLE)
    set(CLANG_COMMAND ${CMAKE_CXX_COMPILER} ${LIBCXX_COMPILE_FLAGS}
        "-print-file-name=lib")
    execute_process(
        COMMAND ${CLANG_COMMAND}
        RESULT_VARIABLE HAD_ERROR
        OUTPUT_VARIABLE LIBRARY_DIR
    )
    string(STRIP "${LIBRARY_DIR}" LIBRARY_DIR)
    set(LIBRARY_DIR "${LIBRARY_DIR}/darwin")
  else()
    set(CLANG_COMMAND ${CMAKE_CXX_COMPILER} ${LIBCXX_COMPILE_FLAGS}
        "--rtlib=compiler-rt" "--print-libgcc-file-name")
    execute_process(
        COMMAND ${CLANG_COMMAND}
        RESULT_VARIABLE HAD_ERROR
        OUTPUT_VARIABLE LIBRARY_FILE
    )
    string(STRIP "${LIBRARY_FILE}" LIBRARY_FILE)
    get_filename_component(LIBRARY_DIR "${LIBRARY_FILE}" DIRECTORY)
  endif()
  if (NOT HAD_ERROR AND EXISTS "${LIBRARY_DIR}")
    message(STATUS "Found compiler-rt directory: ${LIBRARY_DIR}")
    set(${dest} "${LIBRARY_DIR}" PARENT_SCOPE)
  else()
    message(STATUS "Failed to find compiler-rt directory")
  endif()
endfunction()
