cmake_minimum_required(VERSION 3.8)
project(CROSSING_ROAD LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES_OPERATION "src/*.h" "src/*.hpp" "src/*.cpp")
file(GLOB SOURCES_DESIGN "src_design/environment/*.png" "src_design/people/*.png" "src_design/vehicle/*.png" "src_design/animal/*.png" "src_design/font/*.otf" "src_design/font/*.ttf" "src_design/animal/*.wav" "src_design/background/*.png" "src_design/sound/*.wav")

set(PROJECT_SOURCES 
	main.cpp
	${SOURCES_OPERATION}
	${SOURCES_DESIGN}
)

include(FetchContent)
FetchContent_Declare(SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-audio sfml-graphics sfml-network sfml-window)

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    XCODE_GENERATE_SCHEME TRUE
    XCODE_SCHEME_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

if (WIN32) 
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
  COMMAND_EXPAND_LISTS
)
endif()
