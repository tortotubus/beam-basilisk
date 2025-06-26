add_library(ws
  src/ws.c
  src/base64/base64.c
  src/sha1/sha1.c
  src/handshake/handshake.c
)

target_link_libraries(ws pthread)
target_include_directories(ws PUBLIC include)