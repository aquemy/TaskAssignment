######################################################################################
### 0) Include headers
######################################################################################

include_directories(${SIF_SRC_DIR}/src/SIF)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

######################################################################################
### 1) Define test list
######################################################################################

set (TEST_LIST  
        ut-aStar
        ut-atlasGrid
        ut-constraint
        ut-environment
        ut-eval
        ut-ia
        ut-kuhn
        ut-logger
        ut-manualModel
        ut-model
        ut-object
        ut-observer
        ut-path
        ut-quadTree
        ut-rTree
        ut-shortestPath
        ut-shortestPathFactory
        ut-simpleStrategy
        ut-spatialData
        ut-strategy
        ut-task
        ut-taskSpot
        ut-threading
        ut-tree
        ut-treeFactory
        it-assignment
        it-controller
		)

######################################################################################
### 3) Create each test
######################################################################################

foreach (test ${TEST_LIST})
	set ("T_${test}_SOURCES" "${test}.cpp")
    add_executable(${test} ${T_${test}_SOURCES})
    target_link_libraries(${test} sif)
    add_test(${test} ${test}) 
    install(TARGETS ${test} RUNTIME DESTINATION share${INSTALL_SUB_DIR}/test COMPONENT tests)
endforeach (test)
