cmake_minimum_required(VERSION 3.12)

set(ENGINE_PROJECT_NAME tutorialengCore)

##create variable for add public inlude(.hpp/.h) file paths
set(ENGINE_PUBLIC_INCLUDES
	includes/tutorialengCore/Application.hpp
	includes/tutorialengCore/Log.hpp
)

##create variable for add private source(.cpp) file paths
set(ENGINE_PRIVATE_SOURCES
	src/tutorialengCore/Application.cpp
)

add_library(${ENGINE_PROJECT_NAME} STATIC
	${ENGINE_PUBLIC_INCLUDES}
	${ENGINE_PRIVATE_SOURCES}
)

##make our librery public
target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC includes)
##alows to use features from c++ 17
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)

##show path to subdirectory and give to our project another path to copy bin files to correct folder at build folder
##Link it private to our core for being protected from editing from other programs
##1. for glfw
add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glfw)
##2. for spdlog  
add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE spdlog)
##3. gor glad
add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glad)