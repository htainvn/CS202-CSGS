//
//  LaneGenerator.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include <time.h>
#include "src/LaneGenerator.hpp"

void LaneFactory::add_lane(int type, Position pos, Level level) {
    
    Lane* newlane = create_lane(type, pos, level);
    
    if (lanes.size() >= 8) {
        
        if (type != ROAD_TYPE)
        {
            if (lanes.at(7)->type() == ROAD_TYPE) lanes.at(7)->change_status(2);
        }
        else
        {
            delete newlane;
            
            newlane = nullptr;
            
            int changed_type = -1;
            
            newlane = (lanes.at(7)->type() != ROAD_TYPE) ? new Road(tools, 0, 0, 0, 0, level, pos) : new Road(tools, lanes.at(7)->direction(), changed_type, level, pos);
            
            lanes.at(7)->change_status( -1 , -1 , -1 , changed_type);
        }
        
    }
    
    lanes.push_back(newlane);
    
}

bool LaneFactory::detect_outscr()
{
    bool result;
    
    if ((result = lanes.at(0)->position().get_y() >= SCREEN_HEIGHT))
    {
        pop_bottom_lane();
    }
    
    if (result || lanes.at(0)->position().get_y() >= BOUNDARY_LANE)
    {
        if (lanes.size() < 9)
        {
            Level tmp = *level;

            int type = level->spawn_next_lane();
            
            add_lane(type, Position(0, -100 + lanes.at(lanes.size()-1)->position().get_y()), tmp);
        }
    }
    
    return result;
}

void LaneFactory::refactor(float& shift_level) {
    
    //int able_shift = (isShifting) ? std::min(isShifting, 7)-1 : 0;
    
    float tk = shift_level;
    
    float movement;
    
    int t = current();
    
    movement = ((t <= 2) ? LANE_MOVING_SPEED : SHIFT_MOVING_SPEED * std::min(2.5f, shift_level)) * FRAME_RATE_SECOND;
    
    for (int i = 0; i < this->lanes.size(); i++) {
        
        lanes.at(i)->locate_at(0, lanes.at(i)->Lane::position().get_y() + movement);
        
        lanes.at(i)->adjust_objects();
        
    }
    
    shift_level -= (detect_outscr() ? 0.8f : 0.f);
    
    if (current() == 2) shift_level = 0;
    
    if (level->out_of_path() && level->out_of_road()) level->goto_next_level();
}


void LaneFactory::pop_bottom_lane()
{
    if (lanes[0] != nullptr)
    {
        delete lanes[0];
        
        lanes[0] = nullptr;
    }
    
    lanes.erase(lanes.begin());
}


Lane *LaneFactory::create_lane(int type, Position pos, Level level) {
    
    Lane *result = nullptr;
    
    ((type == PATHWAY_TYPE) &&  (result = new Pathway(tools, pos, level)));
    ((type == PATHWAYLIGHT_TYPE) && (result = new PathwayLight(tools, pos, level)));
    ((type == ROAD_TYPE) && (result = new Road(tools, 0, 0, 0, 0, level, pos)));
    
    return (result == nullptr ? new River(tools, level, pos) : result);
}

Lane*& LaneFactory::at(const int index) {
    return lanes.at(index);
}

void LaneFactory::prev_current(People*& mario)
{
    int current_lane = current();
    
    if (current_lane != 0)
    {
        lanes[current_lane]->unset();
        
        this->lanes[current_lane - 1]->set_current(mario);
    }
}

void LaneFactory::next_current(People*& mario)
{
    int current_lane = current();
    
    if (current_lane < 5)
    {
        
        lanes[current_lane]->unset();
        
        lanes[current_lane + 1]->set_current(mario);
        
    }
}

int LaneFactory::current() {
    int r = -1;
    for (int i = 0; i < lanes.size(); i++) {
        if (lanes[i]->is_current()) {
            r = i;
            break;
        }
    }
    return r;
}


void LaneFactory::stop()
{
    for (auto &each : lanes)
    {
        each->stop();
    }
}

void LaneFactory::slowdown() { 
    for (auto &each : lanes)
    {
        each->slowdown();
    }
}

void LaneFactory::run() { 
    for (auto &each : lanes)
    {
        each->run();
    }
}

void LaneFactory::horizontal_movement(People *&mario, int type) {
    int current_lane = current();
    
    if (lanes[current_lane]->type() == RIVER_TYPE) {
        lanes[current_lane]->set_current(mario, type);
    }
    else {
        lanes[current_lane]->set_current(mario);
    }
}


void LaneFactory::loading(std::ifstream& fin) {
    int LANE_SIZE;
    fin >> LANE_SIZE;
    for (int i = 0; i < LANE_SIZE; i++)
    {
        int LANE_TYPE, LEVEL_NUM, LEVEL_PATH, LEVEL_ROAD;
        float LANE_COOR_X, LANE_COOR_Y;
        
        fin >> LANE_TYPE >> LEVEL_NUM >> LEVEL_PATH >> LEVEL_ROAD >> LANE_COOR_X >> LANE_COOR_Y;
        
        add_lane(LANE_TYPE, Position(LANE_COOR_X, LANE_COOR_Y), Level(LEVEL_NUM, LEVEL_ROAD, LEVEL_PATH));
        
        lanes[lanes.size()-1]->loading(fin);
        
    }
}


void LaneFactory::save(std::ofstream& fout) {
    fout << lanes.size() << std::endl;

    for (auto& i : lanes) i->save(fout);
}
