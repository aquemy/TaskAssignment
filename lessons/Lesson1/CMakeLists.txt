# Lesson 1

######################################################################################
### 0) Define files
######################################################################################

set(files
    l1-basicSimulation
    )

######################################################################################
### 1) Create the lesson 
######################################################################################
    
add_lesson(basicSimulation "${files}")

######################################################################################
### 2) Include dependencies
######################################################################################

include_directories(${SIF_SRC_DIR})

