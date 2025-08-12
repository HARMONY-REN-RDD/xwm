# platforms/Linux/CMakeLists.txt

add_executable(xuci_linux ${SRC})

set_target_properties(xuci_linux PROPERTIES OUTPUT_NAME "xuci")

set_target_properties(xuci_linux PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

set(OBJ_FILE "${CMAKE_BINARY_DIR}/platforms/Linux/CMakeFiles/xuci_linux.dir/__/__/src/base_architecture.cpp.o")

set(DESTINATION "${CMAKE_BINARY_DIR}/base_architecture.o")

add_custom_command(TARGET xuci_linux POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different "${OBJ_FILE}" "${DESTINATION}"
)
