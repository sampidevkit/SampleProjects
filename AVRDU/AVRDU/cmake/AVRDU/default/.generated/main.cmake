include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(AVRDU_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(AVRDU_default_default_XC8_FILE_TYPE_assemble)
add_library(AVRDU_default_default_XC8_assemble OBJECT ${AVRDU_default_default_XC8_FILE_TYPE_assemble})
    AVRDU_default_default_XC8_assemble_rule(AVRDU_default_default_XC8_assemble)
    list(APPEND AVRDU_default_library_list "$<TARGET_OBJECTS:AVRDU_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(AVRDU_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(AVRDU_default_default_XC8_assemblePreprocess OBJECT ${AVRDU_default_default_XC8_FILE_TYPE_assemblePreprocess})
    AVRDU_default_default_XC8_assemblePreprocess_rule(AVRDU_default_default_XC8_assemblePreprocess)
    list(APPEND AVRDU_default_library_list "$<TARGET_OBJECTS:AVRDU_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(AVRDU_default_default_XC8_FILE_TYPE_compile)
add_library(AVRDU_default_default_XC8_compile OBJECT ${AVRDU_default_default_XC8_FILE_TYPE_compile})
    AVRDU_default_default_XC8_compile_rule(AVRDU_default_default_XC8_compile)
    list(APPEND AVRDU_default_library_list "$<TARGET_OBJECTS:AVRDU_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(AVRDU_default_image_pnYJdkfx ${AVRDU_default_library_list})

set_target_properties(AVRDU_default_image_pnYJdkfx PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${AVRDU_default_output_dir}")
target_link_libraries(AVRDU_default_image_pnYJdkfx PRIVATE ${AVRDU_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
AVRDU_default_link_rule( AVRDU_default_image_pnYJdkfx)


