#
# interpreter_obj.a
#

set(INTERPRETER_OBJ_SOURCES
  interpreter.c
)

add_library(interpreter_obj OBJECT ${INTERPRETER_OBJ_SOURCES})

target_compile_definitions(interpreter_obj PRIVATE BASILISK=\"${BASILISK}\" )
target_include_directories(interpreter_obj PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/..")
target_include_directories(interpreter_obj PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_include_directories(interpreter_obj PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../..")


#
# interpreter_obj.a
#

set(INTERPRETER_OBJ_SOURCES
  interpreter.c
)

add_library(interpreter_obj-source OBJECT ${INTERPRETER_OBJ_SOURCES})

target_compile_definitions(interpreter_obj-source PRIVATE BASILISK=\"${BASILISK_SOURCE}\" )
target_include_directories(interpreter_obj-source PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/..")
target_include_directories(interpreter_obj-source PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_include_directories(interpreter_obj-source PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../..")