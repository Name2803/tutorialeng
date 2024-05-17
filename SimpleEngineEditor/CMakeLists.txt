cmake_minimum_required(VERSION 3.12)

set(EDITOR_PROJECT_NAME tutorialengEditor)

add_executable(${EDITOR_PROJECT_NAME}
	src/main.cpp
)

##link our libreryies
target_link_libraries(${EDITOR_PROJECT_NAME} tutorialengCore)
##alows to use features from c++ 17
target_compile_features(${EDITOR_PROJECT_NAME} PUBLIC cxx_std_17)

##through EXE file to bin folder
set_target_properties(${EDITOR_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)