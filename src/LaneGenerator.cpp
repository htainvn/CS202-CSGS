//
//  LaneGenerator.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include <time.h>
#include "src/LaneGenerator.hpp"

int LaneGenerator::get_prediction_type() {
    return prediction[0]->get_lane_type();
}

void LaneGenerator::add_lane(ResourceManager& resource_manager, float oy, int type_of_lane) {
    switch(type_of_lane) {
        case 0: {
            Pathway* new_lanep = new Pathway(resource_manager.get_texture("PAVEMENT"));
            new_lanep->allocate_lane_position( resource_manager, 0, oy);
            lanes.push_back(new_lanep);
            break;
        }
        case 1: {
             PathwayLight* new_lane = new PathwayLight(resource_manager.get_texture("PAVEMENT"), resource_manager.get_texture("TRAFFIC_RED"));
             new_lane->allocate_lane_position(resource_manager, 0, oy);
             lanes.push_back(new_lane);
            break;
        }
        case 2: {
            Road* new_lanero = new Road(resource_manager);
            new_lanero->allocate_lane_position(resource_manager, 0, oy);
            lanes.push_back(new_lanero);
            break;
        }
        case 3: {
            River* new_laneri = new River(resource_manager.get_texture("RIVER"));
            new_laneri->allocate_lane_position(resource_manager, 0, oy);
            lanes.push_back(new_laneri);
            break;
        }
    }
}

void LaneGenerator::delete_bottom_lane() {
    int number_of_lanes = this->lanes.size() - 1;
    delete this->lanes[0];
    this->lanes[0] = nullptr;
    for (int i = 0; i < number_of_lanes; i++) {
        this->lanes[i] = this->lanes[i+1];
    }
    this->lanes.resize(number_of_lanes);
}

void LaneGenerator::updating(float moving_speed, sf::Clock& clock, int& isShifting, bool& has_shifted, ResourceManager& resource_manager, bool is_green, int& real_level) {
    
    
    int able_shift = (isShifting) ? std::min(isShifting, 7)-1 : 0;
    
    float movement = moving_speed * FRAME_RATE_SECOND;
    
    for (int i = 0; i < this->lanes.size(); i++) {
        this->lanes[i]->sprite.move(sf::Vector2f(0, movement));
    }
    
    if (this->lanes[0]->sprite.getPosition().y >= BOUNDARY_LANE) {
        if (lanes.size() == SCREEN_HEIGHT / HEIGHT_TITLE) {
            int type_of_spawn_lane = 0;
            if (this->path_left) {
                type_of_spawn_lane = ((this->path_left) == 1);
                this->path_left--;
            }
            else if (this->road_left) {
                type_of_spawn_lane = rand() % 2 + 2;
                this->road_left--;
            }
            this->lanes.push_back(prediction[0]);
            lanes[lanes.size()-1]->allocate_lane_position( resource_manager, 0, -100 + this->lanes[0]->sprite.getPosition().y - BOUNDARY_LANE);
            prediction.erase(prediction.begin());
            add_prediction(resource_manager, type_of_spawn_lane);
        }
        
        if (this->lanes[0]->sprite.getPosition().y >= SCREEN_HEIGHT) {
            delete_bottom_lane();
            if (isShifting) isShifting--;
            has_shifted = true;
            if ((this->lanes[2]->get_lane_type() == 0) || (this->lanes[2]->get_lane_type() == 1)) {
                real_level += (real_level & 0x1);
            }
            else {
                real_level += 1 - (real_level & 0x1);
            }
        }
    }
    
    if (this->path_left == 0 && this->road_left == 0) this->set_level(this->level+1);
    if (!is_green) {
        for (int i = 0; i < this->lanes.size(); i++) {
            lanes[i]->stop_traffic();
        }
    }
}

int LaneGenerator::counting_lanes() {
    return this->lanes.size();
}

Lane*& LaneGenerator::operator[](const int index) {
    return this->lanes[index];
}

LaneGenerator::~LaneGenerator() {
    for (int i = 0; i < lanes.size(); i++) {
        if (lanes[i]) {
            delete lanes[i];
            lanes[i] = nullptr;
        }
    }
}

void LaneGenerator::add_prediction(ResourceManager& resource_manager, int type_of_lane) {
    switch(type_of_lane) {
        case 0: {
            Pathway* new_lanep = new Pathway(resource_manager.get_texture("PAVEMENT"));
            if (!prediction.empty() && prediction[0]->get_lane_type() == 2) {
                prediction[0]->change_position(2);
                prediction[0]->change_texture(resource_manager);
            }
            prediction.push_back(new_lanep);
            break;
        }
        case 1: {
             PathwayLight* new_lane = new PathwayLight(resource_manager.get_texture("PAVEMENT"), resource_manager.get_texture("TRAFFIC_RED"));
            if (!prediction.empty() &&  prediction[0]->get_lane_type() == 2) {
                prediction[0]->change_position(2);
                prediction[0]->change_texture(resource_manager);
            }
             prediction.push_back(new_lane);
            break;
        }
        case 2: {
            Road* new_lanero;
            if (!prediction.empty() && prediction[0]->get_lane_type() != 2) {
                new_lanero = new Road(resource_manager);
            }
            else if (!prediction.empty()) {
                int changed_type = 0;
                new_lanero = new Road(resource_manager, prediction[0]->see_dir(), changed_type);
                prediction[0]->change_top_type(changed_type);
                prediction[0]->change_texture(resource_manager);
            }
            prediction.push_back(new_lanero);
            break;
        }
        case 3: {
            River* new_laneri = new River(resource_manager.get_texture("RIVER"));
            if (!prediction.empty() && prediction[0]->get_lane_type() == 2) {
                prediction[0]->change_position(2);
                prediction[0]->change_texture(resource_manager);
            }
            prediction.push_back(new_laneri);
            break;
        }
    }
}

void LaneGenerator::set_level(int x, int path_left, int road_left) {
    this->level = x;
    this->path_left = path_left;
    this->road_left = road_left;
}

void LaneGenerator::set_level(int x) {
    srand((int) time(0));
    this->level = x;
    this->path_left = rand() % 3 + 1;
    this->road_left = (x-1)/CAR_PER_LANE + 1;
}

Lane*& LaneGenerator::get_prediction(int index) {
    return this->prediction[index];
}

void LaneGenerator::inc_multi_base() {
    this->multi_base += 0.1f;
}

void LaneGenerator::reset_base() {
    this->multi_base = 1.0f;
}

float LaneGenerator::get_base() {
    return this->multi_base;
}

void LaneGenerator::set_cutoff(int time_x) {
    this->cutoff_time = time_x;
}

int LaneGenerator::get_cutoff() {
    return this->cutoff_time;
}
