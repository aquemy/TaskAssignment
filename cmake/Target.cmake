######################################################################################
### cleanall will delete all files and folders in build directory
######################################################################################

if(UNIX)
    add_custom_target(cleanall COMMAND cd ${CMAKE_BINARY_DIR} && rm -rf *)
endif(UNIX)

######################################################################################
### Perform covering test if lcov is found
######################################################################################

if(PROFILING)
    find_program(LCOV 
        NAMES lcov
        PATHS
        "/usr/local/bin /usr/bin [HKEY_LOCAL_MACHINE\\SOFTWARE\\Rational Software\\Purify\\Setup;InstallFolder] [HKEY_CURRENT_USER\\Software]"
        DOC "Path to the memory checking command, used for memory error detection.")
    if(LCOV)
        add_custom_target(coverage
            COMMAND make
            COMMAND ctest
            COMMAND lcov -d . -c -o output.info
            COMMAND lcov -r output.info '/usr*' -o output.info
            COMMAND lcov -r output.info 'test*' -o output.info
            COMMAND genhtml output.info -o coverage/ --highlight --legend
        )
    else(LCOV)
        message(STATUS "Could NOT find Lcov")
    endif(LCOV)
endif(PROFILING)

