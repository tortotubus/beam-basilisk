

# --- config ---------------------------------------------------------

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
add_executable(qcc-install ALIAS qcc)
add_executable(Basilisk::qcc ALIAS qcc)

target_compile_definitions(qcc PRIVATE LIBDIR=\"${LIBDIR}\")
target_compile_definitions(qcc PRIVATE CC99=\"${CC99}\")
target_compile_definitions(qcc PRIVATE CPP99=\"${CPP99}\")
target_compile_definitions(qcc PRIVATE CADNACC=\"${CADNACC}\")
target_compile_definitions(qcc PRIVATE BASILISK=\"${BASILISK}\")

message("qcc using ${BASILISK}")

target_link_libraries(qcc PRIVATE ast m)

# --- include.o ------------------------------------------------------

# add_library(include_obj-source OBJECT include.c)
# target_compile_definitions(include_obj-source PRIVATE LIBDIR=\"${LIBDIR_SOURCE}\")

# --- postproc.o -----------------------------------------------------

# add_library(postproc_obj-source OBJECT postproc.c)
# target_compile_definitions(postproc_obj-source PRIVATE LIBDIR=\"${LIBDIR_SOURCE}\")

# --- qcc (from source tree) ------------------------------------------------------------

# add_executable(qcc-source
#   qcc.c
#   $<TARGET_OBJECTS:include_obj-source>
#   $<TARGET_OBJECTS:postproc_obj-source>
# )

# target_compile_definitions(qcc-source PRIVATE LIBDIR=\"${LIBDIR_SOURCE}\")
# target_compile_definitions(qcc-source PRIVATE CC99=\"${CC99}\")
# target_compile_definitions(qcc-source PRIVATE CPP99=\"${CPP99}\")
# target_compile_definitions(qcc-source PRIVATE CADNACC=\"${CADNACC}\")
# target_compile_definitions(qcc-source PRIVATE BASILISK=\"${BASILISK_SOURCE}\")

# message("qcc-source using ${BASILISK_SOURCE}")

# target_link_libraries(qcc-source PRIVATE ast-source m)

# --- gl -----------------------------------------------------

# add_subdirectory(gl)

# --- wsserver -----------------------------------------------

# add_subdirectory(wsServer)

# --- bview2d ------------------------------------------------

#add_basilisk_source_executable(bview2d bview.c gl ${CMAKE_CURRENT_SOURCE_DIR})
#add_basilisk_source_executable(bview2D bview.c ${CMAKE_CURRENT_SOURCE_DIR})

# target_link_libraries(bview2D PRIVATE 
#   $<TARGET_OBJECTS:fb_tiny> 
#   $<TARGET_OBJECTS:glutils> 
#   $<TARGET_OBJECTS:tinyrenderer> 
#   $<TARGET_OBJECTS:ws>
#   m
# )

# set_target_properties(bview2D PROPERTIES 
#   LINKER_LANGUAGE CXX
# )


# target_compile_definitions(qcc-source PRIVATE LIBDIR=\"${LIBDIR_SOURCE}\")

# # --- bview3d 

# #add_basilisk_source_executable(bview2d bview.c gl ${CMAKE_CURRENT_SOURCE_DIR})
# add_basilisk_source_executable(bview3D bview.c GRID octree)

# target_link_libraries(bview3D PRIVATE 
#   $<TARGET_OBJECTS:fb_tiny> 
#   $<TARGET_OBJECTS:glutils> 
#   $<TARGET_OBJECTS:tinyrenderer> 
#   $<TARGET_OBJECTS:ws>
#   m
# )

# set_target_properties(bview3D PROPERTIES 
#   LINKER_LANGUAGE CXX
# )

# # --- bview2Dm


# #add_basilisk_source_executable(bview2d bview.c gl ${CMAKE_CURRENT_SOURCE_DIR})
# add_basilisk_source_executable(bview2Dm bview.c GRID multigrid)

# target_link_libraries(bview2Dm PRIVATE 
#   $<TARGET_OBJECTS:fb_tiny> 
#   $<TARGET_OBJECTS:glutils> 
#   $<TARGET_OBJECTS:tinyrenderer> 
#   $<TARGET_OBJECTS:ws>
#   m
# )

# set_target_properties(bview2Dm PROPERTIES 
#   LINKER_LANGUAGE CXX
# )


# ---------------------------------------------------------------------