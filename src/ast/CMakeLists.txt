#
# symbols.h
#

set(SYMBOLS_H "${CMAKE_CURRENT_BINARY_DIR}/symbols.h")

add_custom_command(
  OUTPUT ${SYMBOLS_H}
  COMMAND ${CMAKE_COMMAND}
    -DBASILISK_C=${CMAKE_CURRENT_SOURCE_DIR}/basilisk.c
    -DOUT=${SYMBOLS_H}
    -P ${CMAKE_SOURCE_DIR}/cmake/generate_symbols_h.cmake
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/basilisk.c
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Generating symbols.h from basilisk.c"
)

#
# interpreter_obj
#

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
  # ${SYMBOLS_H}
)

add_library(ast_obj OBJECT ${AST_OBJ_SOURCES})

target_compile_definitions(ast_obj PRIVATE BASILISK=\"${BASILISK}\" )
target_include_directories(ast_obj PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_include_directories(ast_obj PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")

add_library(ast STATIC 
  $<TARGET_OBJECTS:ast_obj> 
  $<TARGET_OBJECTS:interpreter_obj>
)

set_target_properties(ast PROPERTIES OUTPUT_NAME "ast")