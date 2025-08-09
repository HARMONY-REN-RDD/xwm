add_executable(x64_win ${SRC})
set_target_properties(x64_win PROPERTIES
    OUTPUT_NAME "x64.exe"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
