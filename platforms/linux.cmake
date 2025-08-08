add_executable(xuci_linux ${SRC})
set_target_properties(xuci_linux PROPERTIES
    OUTPUT_NAME "xuci"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
