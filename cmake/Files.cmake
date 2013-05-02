SET(SIF_SRC_DIR "src/SIF")
SET(SIF_INC_DIR "include/SIF")

set(SRC_FROM_INC
    assignment/assignment.hpp
    assignment/assignmentFactory.hpp
    assignment/kuhn.hpp
    core/activePolicy.hpp
    core/multiThread.hpp
    core/observable.hpp
    core/observablePolicy.hpp
    core/observer.hpp
    core/passivePolicy.hpp
    core/singleThread.hpp
    core/step.hpp
    core/threadingModel.hpp
    environment/coordonate.hpp
    environment/direction.hpp
    environment/dynamicObject.hpp
    environment/environment.hpp
    environment/eval.hpp
    environment/object.hpp
    environment/obstacle.hpp
    environment/resource.hpp
    environment/space.hpp
    environment/spatialData.hpp
    environment/square.hpp
    environment/staticObject.hpp
    environment/taskSpot.hpp
    graph/atlasGrid.hpp
    graph/path.hpp
    graph/quadTree.hpp
    graph/rTree.hpp
    graph/simpleIndex.hpp
    graph/tree.hpp
    graph/treeFactory.hpp
    ia/model/manualModel.hpp
    ia/strategy/simpleStrategy.hpp
    ia/ia.hpp
    ia/model.hpp
    ia/strategy.hpp
    spa/aStar.hpp
    spa/shortestPath.hpp
    spa/shortestPathFactory.hpp
)

set(SRC_FROM_SRC
    constraint/constraint.cpp
    constraint/constraintSystem.cpp
    constraint/customConstraint.cpp
    constraint/stepConstraint.cpp
    core/continue/continue.cpp
    core/continue/stepsContinue.cpp
    core/continue/timeContinue.cpp
    core/controller.cpp
    environment/task.cpp
    utils/baseLogger.cpp
    utils/logger.cpp
    utils/timeManagement.cpp
)

foreach (file ${SRC_FROM_INC})
    LIST(APPEND SRC "${SIF_INC_DIR}/${file}")
endforeach (file)

foreach (file ${SRC_FROM_SRC})
    LIST(APPEND SRC "${SIF_SRC_DIR}/${file}")
endforeach (file)

add_library(sif STATIC ${SRC})

# set the debug suffix
set_target_properties(sif PROPERTIES DEBUG_POSTFIX -d)

set_target_properties(sif PROPERTIES LINKER_LANGUAGE CXX)

# insert the major version number in the output filename
set_target_properties(sif PROPERTIES OUTPUT_NAME "sif")

# setup the install rule
install(TARGETS sif ARCHIVE DESTINATION lib${LIB_SUFFIX} COMPONENT libraries)


######################################################################################
### 0) Include source directories
######################################################################################