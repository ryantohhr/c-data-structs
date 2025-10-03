cmake_minimum_required(VERSION 4.1)
project(c-data-structs)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

function(add_data_structure TARGET)
	file(GLOB_RECURSE sources 
		"${CMAKE_SOURCE_DIR}/src/${TARGET}.c"
		"${CMAKE_SOURCE_DIR}/tests/test_${TARGET}.c"
	)
	add_executable(${TARGET} ${sources})
	target_include_directories(${TARGET} PUBLIC "${CMAKE_SOURCE_DIR}/include")
endfunction()

add_data_structure(queue)
