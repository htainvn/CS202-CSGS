#pragma once

#include <filesystem>

#include <src/ResourceManager.hpp>

//define here
#define state_ptr State*
#define handler_ptr Handler*

#define FRAME_RATE_SECOND (1.0f/1000.0f)
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 700
#define BOUNDARY_LANE 600
#define HEIGHT_TITLE 100
#define dsize 100

#define CAR_PER_LANE 3

#define WORKING_DIR std::filesystem::current_path().string()
#define PAVEMENT_IMAGE_FILE_PATH WORKING_DIR+"/src_design/environment/pavement.png"
#define LEFT_BOTTOMDASH_NORMAL_FILE_PATH WORKING_DIR+"/src_design/environment/left-bottomdash-normal.png"
#define LEFT_BOTTOMDASH_TOP_FILE_PATH WORKING_DIR+"/src_design/environment/left-bottomdash-top.png"
#define LEFT_FULLDASH_NORMAL_FILE_PATH WORKING_DIR+"/src_design/environment/left-fulldash-normal.png"
#define LEFT_NODASH_BOTTOM_FILE_PATH WORKING_DIR+"/src_design/environment/left-nodash-bottom.png"
#define LEFT_NODASH_NORMAL_FILE_PATH WORKING_DIR+"/src_design/environment/left-nodash-normal.png"
#define LEFT_NODASH_TOP_FILE_PATH WORKING_DIR+"/src_design/environment/left-nodash-top.png"
#define LEFT_NOLINE_FILE_PATH WORKING_DIR+"/src_design/environment/left-noline.png"
#define LEFT_TOPDASH_BOTTOM_FILE_PATH WORKING_DIR+"/src_design/environment/left-topdash-bottom.png"
#define LEFT_TOPDASH_NORMAL_FILE_PATH WORKING_DIR+"/src_design/environment/left-topdash-normal.png"
#define RIGHT_BOTTOMDASH_NORMAL_FILE_PATH WORKING_DIR+"/src_design/environment/right-bottomdash-normal.png"
#define RIGHT_BOTTOMDASH_TOP_FILE_PATH WORKING_DIR+"/src_design/environment/right-bottomdash-top.png"
#define RIGHT_FULLDASH_NORMAL_FILE_PATH WORKING_DIR+"/src_design/environment/right-fulldash-normal.png"
#define RIGHT_NODASH_BOTTOM_FILE_PATH WORKING_DIR+"/src_design/environment/right-nodash-bottom.png"
#define RIGHT_NODASH_NORMAL_FILE_PATH WORKING_DIR+"/src_design/environment/right-nodash-normal.png"
#define RIGHT_NODASH_TOP_FILE_PATH WORKING_DIR+"/src_design/environment/right-nodash-top.png"
#define RIGHT_NOLINE_FILE_PATH WORKING_DIR+"/src_design/environment/right-noline.png"
#define RIGHT_TOPDASH_BOTTOM_FILE_PATH WORKING_DIR+"/src_design/environment/right-topdash-bottom.png"
#define RIGHT_TOPDASH_NORMAL_FILE_PATH WORKING_DIR+"/src_design/environment/right-topdash-normal.png"
#define RIVER_FILE_PATH WORKING_DIR+"/src_design/environment/river.png"
#define TRAFFIC_SIGN_RED_FILE_PATH WORKING_DIR+"/src_design/environment/trafficsign_red.png"
#define TRAFFIC_SIGN_YELLOW_FILE_PATH WORKING_DIR+"/src_design/environment/trafficsign_yellow.png"
#define TRAFFIC_SIGN_GREEN_FILE_PATH WORKING_DIR+"/src_design/environment/trafficsign_green.png"

#define MARIO_FORWARD_FILE_PATH WORKING_DIR+"/src_design/people/mario_forward.png"
#define MARIO_DOWNWARD_FILE_PATH WORKING_DIR+"/src_design/people/mario_down.png"
#define MARIO_RIGHT_FILE_PATH WORKING_DIR+"/src_design/people/mario_right.png"
#define MARIO_LEFT_FILE_PATH WORKING_DIR+"/src_design/people/mario_left.png"

#define CL_0 WORKING_DIR+"/src_design/vehicle/CL_0.png"
#define CL_1 WORKING_DIR+"/src_design/vehicle/CL_1.png"
#define CL_2 WORKING_DIR+"/src_design/vehicle/CL_2.png"
#define CL_3 WORKING_DIR+"/src_design/vehicle/CL_3.png"
#define CL_4 WORKING_DIR+"/src_design/vehicle/CL_4.png"
#define CL_5 WORKING_DIR+"/src_design/vehicle/CL_5.png"
#define CL_6 WORKING_DIR+"/src_design/vehicle/CL_6.png"
#define CL_7 WORKING_DIR+"/src_design/vehicle/CL_7.png"
#define CL_8 WORKING_DIR+"/src_design/vehicle/CL_8.png"
#define CR_0 WORKING_DIR+"/src_design/vehicle/CR_0.png"
#define CR_1 WORKING_DIR+"/src_design/vehicle/CR_1.png"
#define CR_2 WORKING_DIR+"/src_design/vehicle/CR_2.png"
#define CR_3 WORKING_DIR+"/src_design/vehicle/CR_3.png"
#define CR_4 WORKING_DIR+"/src_design/vehicle/CR_4.png"
#define CR_5 WORKING_DIR+"/src_design/vehicle/CR_5.png"
#define CR_6 WORKING_DIR+"/src_design/vehicle/CR_6.png"
#define CR_7 WORKING_DIR+"/src_design/vehicle/CR_7.png"
#define CR_8 WORKING_DIR+"/src_design/vehicle/CR_8.png"

#define HIPPO_RIGHT_FILE_PATH WORKING_DIR+"/src_design/animal/hippo_right.png"
#define HIPPO_LEFT_FILE_PATH WORKING_DIR+"/src_design/animal/hippo_left.png"
#define CROC_RIGHT_FILE_PATH WORKING_DIR+"/src_design/animal/croc_right.png"
#define CROC_LEFT_FILE_PATH WORKING_DIR+"/src_design/animal/croc_left.png"

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
