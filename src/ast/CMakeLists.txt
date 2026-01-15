add_subdirectory(interpreter)

#
# grammar + grammar.h
#

add_executable(grammar grammar.c)

set(YACC_IN   "${CMAKE_CURRENT_SOURCE_DIR}/basilisk.yacc")
set(YACC_OUT  "${CMAKE_CURRENT_BINARY_DIR}/grammar.h")

add_custom_command(
  OUTPUT ${YACC_OUT}
  COMMAND grammar < ${YACC_IN} > ${YACC_OUT}
  DEPENDS grammar ${YACC_IN}
  COMMENT "Generating grammar.h from basilisk.yacc"
)

#
# ast.o
#

set(AST_OBJ_SOURCES
  ast.c
  tokens.c
  basilisk.c
  translate.c
  allocator.c
  faststack.c
  stencil.c
  types.c
  references.c
  kernels.c
  check.c
  ${YACC_OUT}
)

#
# ast-obj-install
#

add_library(ast-obj-install OBJECT ${AST_OBJ_SOURCES})

target_compile_definitions(ast-obj-install PRIVATE BASILISK=\"${BASILISK}\" )
target_include_directories(ast-obj-install PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_include_directories(ast-obj-install PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")


add_library(ast-install STATIC 
  $<TARGET_OBJECTS:ast-obj-install> 
  $<TARGET_OBJECTS:interpreter-obj-install>
)

set_target_properties(ast-install PROPERTIES OUTPUT_NAME "ast-install")

#
# ast-obj-toolchain
#

add_library(ast-obj-toolchain OBJECT ${AST_OBJ_SOURCES})

target_compile_definitions(ast-obj-toolchain PRIVATE BASILISK=\"${BASILISK_SOURCE}\" )
target_include_directories(ast-obj-toolchain PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_include_directories(ast-obj-toolchain PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")


add_library(ast-toolchain STATIC 
  $<TARGET_OBJECTS:ast-obj-toolchain> 
  $<TARGET_OBJECTS:interpreter-obj-toolchain>
)

set_target_properties(ast-toolchain PROPERTIES OUTPUT_NAME "ast-toolchain")