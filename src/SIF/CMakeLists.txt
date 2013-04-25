set(SRC
    constraint/constraint.cpp
    constraint/stepConstraint.cpp
    utils/baseLogger.cpp
    utils/logger.cpp
    utils/timeManagement.cpp
    core/controller.cpp
    core/continue/continue.cpp
    core/continue/stepsContinue.cpp
    core/continue/timeContinue.cpp
    environment/task.cpp
)

add_library(sif STATIC ${SRC})

# set the debug suffix
set_target_properties(sif PROPERTIES DEBUG_POSTFIX -d)

# insert the major version number in the output filename
set_target_properties(sif PROPERTIES OUTPUT_NAME "sif")

# setup the install rule
install(TARGETS sif ARCHIVE DESTINATION lib${LIB_SUFFIX} COMPONENT libraries)


######################################################################################
### 0) Include source directories
######################################################################################

#add_subdirectory(utils)
