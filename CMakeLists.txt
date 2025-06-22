cmake_minimum_required(VERSION 3.10)
project(basilisk C)

# Project settings
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Install settings
include(GNUInstallDirs)

# --- config ---------------------------------------------------------

set(BASILISK "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/basilisk/")
set(LIBDIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/basilisk/")

# Recurse targets
add_subdirectory(src)

# Install the qcc executable and basilisk header libraries
install(TARGETS qcc RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY "${CMAKE_SOURCE_DIR}/src/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/basilisk" FILES_MATCHING PATTERN "*.h")