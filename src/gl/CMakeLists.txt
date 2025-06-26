# Tiny Renderer
add_subdirectory(tinyrenderer)

# Bison
# find_package(BISON REQUIRED)
# BISON_TARGET(parser
#   ${CMAKE_CURRENT_SOURCE_DIR}/parser.y
#   ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.c
#   DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.h
# )

# Parser
add_executable(parser parser.tab.c)
target_compile_definitions(parser PRIVATE STANDALONE=1)
target_link_libraries(parser PRIVATE m)

# fb_tiny
add_library(fb_tiny STATIC fb_tiny.c $<TARGET_OBJECTS:tinyrenderer>)
target_include_directories(fb_tiny PRIVATE "${CMAKE_SOURCE_DIR}/tinyrenderer")
target_link_libraries(fb_tiny PRIVATE m)

# Libglutils
add_library(glutils STATIC   
  trackball.c
  utils.c      
  polygonize.c
  og_stroke_mono_roman.c
  TinyPngOut.c
  parser.tab.c
)
target_link_libraries(glutils PRIVATE m)  
target_include_directories(glutils
  PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
)


