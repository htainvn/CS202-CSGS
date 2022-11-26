//
//  LaneGenerator.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include <time.h>
#include "src/LaneGenerator.hpp"

void LaneFactory::add_lane(int type, Position pos) {
    
    Lane* newlane = create_lane(type, pos);
    
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
            
            newlane = (lanes.at(7)->type() != ROAD_TYPE) ? new Road(tools, 0, 0, 0, 0, *level, pos) : new Road(tools, lanes.at(7)->direction(), changed_type, *level, pos);
            
            lanes.at(7)->change_status( -1 , -1 , -1 , changed_type);
        }
        
    }
    
    newlane->set_level(*level);
    
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
            int type = level->spawn_next_lane();
            
            add_lane(type, Position(0, -100 + lanes.at(lanes.size()-1)->position().get_y()));
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


Lane *LaneFactory::create_lane(int type, Position pos) {
    
    Lane *result = nullptr;
    
    ((type == PATHWAY_TYPE) &&  (result = new Pathway(tools, pos)));
    ((type == PATHWAYLIGHT_TYPE) && (result = new PathwayLight(tools, pos)));
    ((type == ROAD_TYPE) && (result = new Road(tools, 0, 0, 0, 0, *level, pos)));
    
    return (result == nullptr ? new River(tools, pos) : result);
}

Lane*& LaneFactory::at(const int index) {
    return lanes.at(index);
}

void LaneFactory::prev_current(People*& mario)
{
    int t = current();
    
    if (t != 0)
    {
        lanes[t]->unset();
        
        this->lanes[t - 1]->set_current(mario);
    }
}

void LaneFactory::next_current(People*& mario)
{
    int t = current();
    
    if (t < 5)
    {
        lanes[t]->unset();
        
        this->lanes[t + 1]->set_current(mario);
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

