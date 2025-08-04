add_executable(xuci_win ${SRC})
set_target_properties(xuci_win PROPERTIES
    OUTPUT_NAME "xuci.exe"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
