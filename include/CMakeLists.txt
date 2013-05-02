set(SRC
    assignment/assignment.cpp
    assignment/assignmentFactory.cpp
    assignment/kuhn.cpp
    constraint/constraint.cpp
    constraint/constraintSystem.cpp
    constraint/customConstraint.cpp
    constraint/stepConstraint.cpp
    core/continue/continue.cpp
    core/continue/stepsContinue.cpp
    core/continue/timeContinue.cpp
    core/activePolicy.cpp
    core/controller.cpp
    core/multiThread.cpp
    core/observable.cpp
    core/observablePolicy.cpp
    core/observer.cpp
    core/passivePolicy.cpp
    core/singleThread.cpp
    core/step.cpp
    core/threadingModel.cpp
    environment/coordonate.cpp
    environment/direction.cpp
    environment/dynamicObject.cpp
    environment/environment.cpp
    environment/eval.cpp
    environment/object.cpp
    environment/obstacle.cpp
    environment/resource.cpp
    environment/space.cpp
    environment/spatialData.cpp
    environment/square.cpp
    environment/staticObject.cpp
    environment/task.cpp
    environment/taskSpot.cpp
    graph/atlasGrid.cpp
    graph/path.cpp
    graph/quadTree.cpp
    graph/rTree.cpp
    graph/tree.cpp
    graph/treeFactory.cpp
    ia/model/manualModel.cpp
    ia/strategy/simpleStrategy.cpp
    ia/ia.cpp
    ia/model.cpp
    ia/strategy.cpp
    spa/aStar.cpp
    spa/shortestPath.cpp
    spa/shortestPathFactory.cpp
    utils/baseLogger.cpp
    utils/logger.cpp
    utils/timeManagement.cpp
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