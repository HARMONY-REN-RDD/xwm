add_executable(x64_linux ${SRC})
set_target_properties(x64_linux PROPERTIES
    OUTPUT_NAME "x64"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
