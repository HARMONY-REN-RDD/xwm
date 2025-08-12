# platforms/Linux/CMakeLists.txt

add_executable(xuci_win ${SRC})

set_target_properties(xuci_win PROPERTIES OUTPUT_NAME "xuci")

set_target_properties(xuci_win PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

set(OBJ_FILE "${CMAKE_BINARY_DIR}/platforms/Windows/CMakeFiles/xuci_win.dir/__/__/src/base_architecture.cpp.obj")

set(DESTINATION "${CMAKE_BINARY_DIR}/base_architecture.obj")

add_custom_command(TARGET xuci_win POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different "${OBJ_FILE}" "${DESTINATION}"
)
