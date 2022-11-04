#pragma once

#include <filesystem>
#include <ResourceManager.hpp>

//define here
#define state_ptr State*
#define handler_ptr Handler*

#define FRAME_RATE_SECOND (1.0f/1000.0f)
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 700
#define BOUNDARY_LANE 600
#define HEIGHT_TITLE 100
#define WORKING_DIR std::filesystem::current_path()
#define PAVEMENT_IMAGE_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/pavement.png"
#define LEFT_BOTTOMDASH_NORMAL_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/left-bottomdash-normal.png"
#define LEFT_BOTTOMDASH_TOP_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/left-bottomdash-top.png"
#define LEFT_FULLDASH_NORMAL_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/left-fulldash-normal.png"
#define LEFT_NODASH_BOTTOM_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/left-nodash-bottom.png"
#define LEFT_NODASH_NORMAL_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/left-nodash-normal.png"
#define LEFT_NODASH_TOP_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/left-nodash-top.png"
#define LEFT_NOLINE_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/left-noline.png"
#define LEFT_TOPDASH_BOTTOM_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/left-topdash-bottom.png"
#define LEFT_TOPDASH_NORMAL_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/left-topdash-normal.png"
#define RIGHT_BOTTOMDASH_NORMAL_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/right-bottomdash-normal.png"
#define RIGHT_BOTTOMDASH_TOP_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/right-bottomdash-top.png"
#define RIGHT_FULLDASH_NORMAL_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/right-fulldash-normal.png"
#define RIGHT_NODASH_BOTTOM_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/right-nodash-bottom.png"
#define RIGHT_NODASH_NORMAL_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/right-nodash-normal.png"
#define RIGHT_NODASH_TOP_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/right-nodash-top.png"
#define RIGHT_NOLINE_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/right-noline.png"
#define RIGHT_TOPDASH_BOTTOM_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/right-topdash-bottom.png"
#define RIGHT_TOPDASH_NORMAL_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/right-topdash-normal.png"
#define RIVER_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/river.png"
#define TRAFFIC_SIGN_RED_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/trafficsign_red.png"
#define TRAFFIC_SIGN_YELLOW_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/trafficsign_yellow.png"
#define TRAFFIC_SIGN_GREEN_FILE_PATH "/Users/hoangtheanh/Documents/HCMUS/CS202/Project/environment/trafficsign_green.png"

#define PATHWAY_TYPE 0
#define ROAD_TYPE 1
#define RIVER_TYPE 2


#define LANE_MOVING_SPEED 20.f
#define SHIFT_MOVING_SPEED 300.f
#define LANE_SPAWN_SPEED 0.2f


class Coordinate {
private:
    int x = 0;
    int y = 0;
public:
    Coordinate() = default;
    Coordinate(int _x, int _y) {
        this->x = _x;
        this->y = _y;
    }
    Coordinate(const Coordinate& another) {
        this->x = another.x;
        this->y = another.y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
};
