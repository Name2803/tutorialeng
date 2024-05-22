cmake_minimum_required(VERSION 3.12)

set(ENGINE_PROJECT_NAME tutorialengCore)

add_library(${ENGINE_PROJECT_NAME} STATIC
	includes/tutorialengCore/Utils/test.hpp
	src/tutorialengCore/Utils/test.cpp
)

##make our librery public
target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC includes)
##alows to use features from c++ 17
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)

##show path to subdirectory and give to our project another path to copy bin files to correct folder at build folder
add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
##Link it private to our core for being protected from editing from other programs
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glfw)