cmake_minimum_required(VERSION 3.10)
project(basilisk 
  VERSION 1.0.0
  LANGUAGES C CXX
)

# Project settings
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# --- basilisk c target helper  -----

include(${CMAKE_SOURCE_DIR}/cmake/BasiliskCTargets.cmake)


# --- 

# Install settings
include(GNUInstallDirs)

# --- config ---------------------------------------------------------

include(${CMAKE_SOURCE_DIR}/cmake/detect_compiler.cmake)
detect_c_compiler(COMP)

message(STATUS " → C compiler ID:      ${COMP_ID}")
message(STATUS " → C compiler version: ${COMP_VERSION}")
message(STATUS " → C compiler path:    ${COMP_PATH}")

# ——— C99 flags ———

if(COMP_ID STREQUAL GNU)

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

elseif(COMP_ID STREQUAL "Clang")

  set(C99_FLAGS
      "-std=c99 -D_XOPEN_SOURCE=700"
      CACHE STRING "Flags to pass to a C99 compiler"
  )

  set(CC99
      "${CMAKE_C_COMPILER} ${C99_FLAGS} -pedantic  -Wno-unused-result"
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

elseif(COMP_ID STREQUAL "Intel")

  set(CC99
      "icc -std=c99 -D_POSIX_SOURCE -D_BSD_SOURCE"
      CACHE STRING "Command line used by qcc to invoke a C99 compiler"
  )

endif()

# --- hardlinks for qcc

set(BASILISK "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/basilisk/")
set(LIBDIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/basilisk/")

set(BASILISK_SOURCE "${CMAKE_SOURCE_DIR}/src/")
set(LIBDIR_SOURCE "${CMAKE_SOURCE_DIR}/src/")

# --- subdir

# Recurse targets
add_subdirectory(src)

# --- export

include(CMakePackageConfigHelpers)

# 2) configure the <build>/BasiliskConfig.cmake that find_package() will use
configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/BasiliskConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/BasiliskConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/basilisk"
)

# 3) write the version file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/BasiliskConfigVersion.cmake"
  VERSION        ${PROJECT_VERSION}
  COMPATIBILITY  AnyNewerVersion
)

# 4) collect the executables you want to export
set(BASILISK_EXECUTABLES
  qcc
  bview2D
  bview3D
  bview2Dm
)

# 5) install & export those targets
install(TARGETS ${BASILISK_EXECUTABLES}
  EXPORT      BasiliskTargets
  RUNTIME     DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# 6) install the export file itself
install(EXPORT BasiliskTargets
  FILE        BasiliskTargets.cmake
  NAMESPACE   Basilisk::
  DESTINATION "lib/cmake/basilisk"
)

# 7) install all headers under include/basilisk
install(DIRECTORY "${CMAKE_SOURCE_DIR}/src/"
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/basilisk
  FILES_MATCHING PATTERN "*.h"
)

# 8) install the generated Config files
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/BasiliskConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/BasiliskConfigVersion.cmake"
  DESTINATION "lib/cmake/basilisk"
)