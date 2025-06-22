

# --- config ---------------------------------------------------------

# ——— C99 flags ———
set(C99_FLAGS
    "-std=c99 -D_XOPEN_SOURCE=700"
    CACHE STRING "Flags to pass to a C99 compiler"
)

set(CC99
    "${CMAKE_C_COMPILER} ${C99_FLAGS} -D_GNU_SOURCE=1 -pedantic -Wno-unused-result -Wno-overlength-strings -fno-diagnostics-show-caret"
    CACHE STRING "Command line used by qcc to invoke a C99 compiler"
)

# ——— CADNA compiler and libraries ———
set(CADNACC
    "clang -D_CADNA=1 -x c++ -m64 -Wno-unused-function -Wno-unused-result -Wno-c++11-compat-deprecated-writable-strings -Wno-address-of-array-temporary"
    CACHE STRING "Compiler flags for building with CADNA"
)

set(CADNALIBS
    "-lcadnaC -lstdc++"
    CACHE STRING "Libraries to link against when using CADNA"
)


# --- libast.a -------------------------------------------------------

add_subdirectory(ast)

# --- include.o ------------------------------------------------------

add_library(include_obj OBJECT include.c)
target_compile_definitions(include_obj PRIVATE LIBDIR=\"${LIBDIR}\")

# --- postproc.o -----------------------------------------------------

add_library(postproc_obj OBJECT postproc.c)
target_compile_definitions(postproc_obj PRIVATE LIBDIR=\"${LIBDIR}\")

# --- qcc ------------------------------------------------------------

add_executable(qcc
  qcc.c
  $<TARGET_OBJECTS:include_obj>
  $<TARGET_OBJECTS:postproc_obj>
)

target_compile_definitions(qcc PRIVATE LIBDIR=\"${LIBDIR}\")
target_compile_definitions(qcc PRIVATE CC99=\"${CC99}\")
target_compile_definitions(qcc PRIVATE CPP99=\"${CPP99}\")
target_compile_definitions(qcc PRIVATE CADNACC=\"${CADNACC}\")
target_compile_definitions(qcc PRIVATE BASILISK=\"${BASILISK}\")

target_link_libraries(qcc PRIVATE ast m)

# --- solver libraries ------------------------------------------------

# ---------------------------------------------------------------------