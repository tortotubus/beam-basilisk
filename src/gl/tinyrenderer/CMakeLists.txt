enable_language(CXX)

#set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -std=c11 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

add_library(tinyrenderer OBJECT
  tiny.c
  model.cpp
  tgaimage.cpp
  #main.cpp
)

target_include_directories(tinyrenderer PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}     
  ${CMAKE_CURRENT_SOURCE_DIR}/.. 
)
