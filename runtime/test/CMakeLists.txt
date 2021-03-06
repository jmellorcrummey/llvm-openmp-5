# CMakeLists.txt file for unit testing OpenMP host runtime library.
include(CheckFunctionExists)
include(CheckLibraryExists)

# Some tests use math functions
check_library_exists(m sqrt "" LIBOMP_HAVE_LIBM)
# When using libgcc, -latomic may be needed for atomics
# (but when using compiler-rt, the atomics will be built-in)
# Note: we can not check for __atomic_load because clang treats it
# as special built-in and that breaks CMake checks
check_function_exists(__atomic_load_1 LIBOMP_HAVE_BUILTIN_ATOMIC)
if(NOT LIBOMP_HAVE_BUILTIN_ATOMIC)
  check_library_exists(atomic __atomic_load_1 "" LIBOMP_HAVE_LIBATOMIC)
else()
  # not needed
  set(LIBOMP_HAVE_LIBATOMIC 0)
endif()

macro(pythonize_bool var)
  if (${var})
    set(${var} True)
  else()
    set(${var} False)
  endif()
endmacro()

pythonize_bool(LIBOMP_USE_HWLOC)
pythonize_bool(LIBOMP_OMPT_SUPPORT)
pythonize_bool(LIBOMP_OMPT_OPTIONAL)
pythonize_bool(LIBOMP_HAVE_LIBM)
pythonize_bool(LIBOMP_HAVE_LIBATOMIC)

add_openmp_testsuite(check-libomp "Running libomp tests" ${CMAKE_CURRENT_BINARY_DIR} DEPENDS omp)
# Add target check-ompt, but make sure to not add the tests twice to check-openmp.
set(EXCLUDE_FROM_ALL True)
add_openmp_testsuite(check-ompt "Running OMPT tests" ${CMAKE_CURRENT_BINARY_DIR}/ompt DEPENDS omp)


# next ones added by msi
set(EXCLUDE_FROM_ALL True)
add_openmp_testsuite(cancel "Running ompt/cancel tests" ${CMAKE_CURRENT_BINARY_DIR}/ompt/cancel/ DEPENDS omp)

set(EXCLUDE_FROM_ALL True)
add_openmp_testsuite(chkompt "Running ompt/chkompt test" ${CMAKE_CURRENT_BINARY_DIR}/ompt/chkompt DEPENDS omp)

set(EXCLUDE_FROM_ALL True)
add_openmp_testsuite(loadtool "Running ompt/loadtool test" ${CMAKE_CURRENT_BINARY_DIR}/ompt/loadtool DEPENDS omp)

set(EXCLUDE_FROM_ALL True)
add_openmp_testsuite(misc "Running ompt/misc test" ${CMAKE_CURRENT_BINARY_DIR}/ompt/misc DEPENDS omp)

set(EXCLUDE_FROM_ALL True)
add_openmp_testsuite(parallel "Running ompt/parallel tests" ${CMAKE_CURRENT_BINARY_DIR}/ompt/parallel/ DEPENDS omp)

set(EXCLUDE_FROM_ALL True)
add_openmp_testsuite(tasks "Running ompt/tasks tests" ${CMAKE_CURRENT_BINARY_DIR}/ompt/tasks/ DEPENDS omp)

set(EXCLUDE_FROM_ALL True)
add_openmp_testsuite(synchronization "Running ompt/synchronization tests" ${CMAKE_CURRENT_BINARY_DIR}/ompt/synchronization/ DEPENDS omp)

set(EXCLUDE_FROM_ALL True)
add_openmp_testsuite(worksharing "Running ompt/worksharing tests" ${CMAKE_CURRENT_BINARY_DIR}/ompt/worksharing/ DEPENDS omp)


# Configure the lit.site.cfg.in file
set(AUTO_GEN_COMMENT "## Autogenerated by libomp configuration.\n# Do not edit!")
configure_file(lit.site.cfg.in lit.site.cfg @ONLY)
