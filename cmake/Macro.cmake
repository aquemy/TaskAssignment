######################################################################################
### add_lesson(module target files)
### Paramaters files must have the same name as cpp file. No need to have a .param
### file. CMake will check if such a file exists.
######################################################################################

macro(add_lesson target files)
    foreach(i ${files})
        if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${i}.param)
            add_executable(${i} ${i}.cpp)
        else(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${i}.param)
            if(${CMAKE_VERBOSE_MAKEFILE})
                message(STATUS "Copying ${i}.param")
            endif(${CMAKE_VERBOSE_MAKEFILE})
            execute_process(
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
			        ${CMAKE_CURRENT_SOURCE_DIR}/${i}.param
			        ${CMAKE_CURRENT_BINARY_DIR}/${i}.param)
	        add_executable(${i}
		        ${i}.cpp
		        ${CMAKE_CURRENT_BINARY_DIR}/${i}.param)
        endif(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${i}.param)
	    target_link_libraries(${i} sif)
	endforeach(i)
	
	# Custom target
	add_custom_target(${target} DEPENDS
			${files}
			${files}.param)
endmacro()
