#
# interpreter_obj.a
#

set(INTERPRETER_OBJ_SOURCES
  interpreter.c
)

add_library(interpreter-obj-install OBJECT ${INTERPRETER_OBJ_SOURCES})

target_compile_definitions(interpreter-obj-install PRIVATE BASILISK=\"${BASILISK}\" )
target_include_directories(interpreter-obj-install PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/..")
target_include_directories(interpreter-obj-install PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_include_directories(interpreter-obj-install PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../..")

add_library(interpreter-obj-toolchain OBJECT ${INTERPRETER_OBJ_SOURCES})

target_compile_definitions(interpreter-obj-toolchain PRIVATE BASILISK=\"${BASILISK_SOURCE}\" )
target_include_directories(interpreter-obj-toolchain PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/..")
target_include_directories(interpreter-obj-toolchain PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_include_directories(interpreter-obj-toolchain PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../..")