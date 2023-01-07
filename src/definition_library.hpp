#pragma once

#include <filesystem>
#include <SFML/Graphics.hpp>
using namespace sf;

#include <src/ResourceManager.hpp>

//define here
#define state_ptr State*
#define handler_ptr Handler*
#define level_ptr Level*
#define lane_ptr Lane*
#define resource_ptr ResourceManager*

#define FRAME_RATE_SECOND (1.0f/1000.0f)
#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 700
#define BOUNDARY_LANE 600
#define HEIGHT_TITLE 100
#define dsize 100
#define people_size 32

#define CAR_PER_LANE 3

#define WORKING_DIR std::filesystem::current_path().string()

#define LOST_BACKGROUND "_lost_background.png"
#define HEADSTONE "_headstone.png"

#define PAVEMENT_IMAGE_FILE_PATH "_pavement.png"
#define LEFT_BOTTOMDASH_NORMAL_FILE_PATH "_left-bottomdash-normal.png"
#define LEFT_BOTTOMDASH_TOP_FILE_PATH "_left-bottomdash-top.png"
#define LEFT_FULLDASH_NORMAL_FILE_PATH "_left-fulldash-normal.png"
#define LEFT_NODASH_BOTTOM_FILE_PATH "_left-nodash-bottom.png"
#define LEFT_NODASH_NORMAL_FILE_PATH "_left-nodash-normal.png"
#define LEFT_NODASH_TOP_FILE_PATH "_left-nodash-top.png"
#define LEFT_NOLINE_FILE_PATH "_left-noline.png"
#define LEFT_TOPDASH_BOTTOM_FILE_PATH "_left-topdash-bottom.png"
#define LEFT_TOPDASH_NORMAL_FILE_PATH "_left-topdash-normal.png"
#define RIGHT_BOTTOMDASH_NORMAL_FILE_PATH "_right-bottomdash-normal.png"
#define RIGHT_BOTTOMDASH_TOP_FILE_PATH "_right-bottomdash-top.png"
#define RIGHT_FULLDASH_NORMAL_FILE_PATH "_right-fulldash-normal.png"
#define RIGHT_NODASH_BOTTOM_FILE_PATH "_right-nodash-bottom.png"
#define RIGHT_NODASH_NORMAL_FILE_PATH "_right-nodash-normal.png"
#define RIGHT_NODASH_TOP_FILE_PATH "_right-nodash-top.png"
#define RIGHT_NOLINE_FILE_PATH "_right-noline.png"
#define RIGHT_TOPDASH_BOTTOM_FILE_PATH "_right-topdash-bottom.png"
#define RIGHT_TOPDASH_NORMAL_FILE_PATH "_right-topdash-normal.png"
#define RIVER_FILE_PATH "_river.png"
#define TRAFFIC_SIGN_RED_FILE_PATH "_trafficsign_red.png"
#define TRAFFIC_SIGN_YELLOW_FILE_PATH "_trafficsign_yellow.png"
#define TRAFFIC_SIGN_GREEN_FILE_PATH "_trafficsign_green.png"

#define MARIO_FORWARD_FILE_PATH "_people_StandForward.png"
#define MARIO_DOWNWARD_FILE_PATH "_people_StandDown.png"
#define MARIO_RIGHT_FILE_PATH "_people_StandRight.png"
#define MARIO_LEFT_FILE_PATH "_people_StandLeft.png"
#define MARIO_MOVEFORWARD_FILE_PATH "_people_GoForward.png"
#define MARIO_RUNFORWARD_FILE_PATH "_people_RunForward.png"
#define MARIO_MOVEDOWNWARD_FILE_PATH "_people_GoDown.png"
#define MARIO_RUNDOWN_FILE_PATH "_people_RunDown.png"
#define MARIO_MOVERIGHT_FILE_PATH "_people_GoRight.png"
#define MARIO_RUNRIGHT_FILE_PATH "_people_RunRight.png"
#define MARIO_MOVELEFT_FILE_PATH "_people_GoLeft.png"
#define MARIO_RUNLEFT_FILE_PATH "_people_RunLeft.png"

#define CL_0 "_CL_0.png"
#define CL_1 "_CL_1.png"
#define CL_2 "_CL_2.png"
#define CL_3 "_CL_3.png"
#define CL_4 "_CL_4.png"
#define CL_5 "_CL_5.png"
#define CL_6 "_CL_6.png"
#define CL_7 "_CL_7.png"
#define CL_8 "_CL_8.png"
#define CR_0 "_CR_0.png"
#define CR_1 "_CR_1.png"
#define CR_2 "_CR_2.png"
#define CR_3 "_CR_3.png"
#define CR_4 "_CR_4.png"
#define CR_5 "_CR_5.png"
#define CR_6 "_CR_6.png"
#define CR_7 "_CR_7.png"
#define CR_8 "_CR_8.png"

#define HIPPO_RIGHT_FILE_PATH "_zombie_right.png"
#define HIPPO_LEFT_FILE_PATH "_zombie_left.png"
#define CROC_RIGHT_FILE_PATH "_croc_right.png"
#define CROC_LEFT_FILE_PATH "_croc_left.png"

#define LOG_PATH "_log.png"

#define PATHWAY_TYPE 0
#define PATHWAYLIGHT_TYPE 1
#define ROAD_TYPE 2
#define RIVER_TYPE 3


#define LANE_MOVING_SPEED 20.f
#define SHIFT_MOVING_SPEED 300.f
#define LANE_SPAWN_SPEED 0.2f

#define YELLOW_TIME_START 14
#define RED_TIME_END 6
#define GREEN_TIME_END 15

#define RED_COUNT_DOWN GREEN_TIME_END-3
#define GREEN_COUNT_DOWN RED_TIME_END-3

#define FONT_PATH_FILE WORKING_DIR+"/src_design/font/TextaPro-Medium.otf"
#define FONT_MENU_PATH_FILE WORKING_DIR + "/src_design/font/AwareBold-qZo3x.ttf"
#define FONT_MENU_OPTION_PATH_FILE WORKING_DIR + "/src_design/font/Rubik-VariableFont_wght.ttf"

#define DATA_FILE_PATH WORKING_DIR + "/datagame/"

#define	MENU_BACKGROUND_PATH_FILE WORKING_DIR + "/src_design/background/menu_3.png"
#define	OPTIONS_BACKGROUND_PATH_FILE WORKING_DIR + "/src_design/background/options.png"
#define	ABOUT_BACKGROUND_PATH_FILE WORKING_DIR + "/src_design/background/about.png"

//sound and music
#define RIVER_SOUND_FILE_PATH "river_sound.wav"

#define ZOMBIE_SOUND_FILE_PATH "zombie_sound.wav"
#define CROC_SOUND_FILE_PATH "croc_sound.wav"
#define CAR_SOUND_FILE_PATH "car_sound.wav"
#define STONE_SOUND_FILE_PATH "stone_rolling.wav"

#define LAVA_THEME_SOUND_FILE_PATH WORKING_DIR + "/src_design/sound/lava_theme_sound.wav"
#define NORMAL_THEME_SOUND_FILE_PATH WORKING_DIR + "/src_design/sound/normal_theme_sound.wav"