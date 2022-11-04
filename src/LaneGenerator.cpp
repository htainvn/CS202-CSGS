//
//  LaneGenerator.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "LaneGenerator.hpp"

int LaneGenerator::get_prediction_type() {
    return prediction[0].get_lane_type();
}

void LaneGenerator::add_lane(ResourceManager& resource_manager, float oy, int type_of_lane) {
    switch(type_of_lane) {
        case 0:
            Pathway new_lane = Pathway(resource_manager.get_texture("PAVEMENT"));
            new_lane.allocate_lane_position(0, oy);
            if (get_prediction_type() == 1) {
                
            }
            lanes.push_back(new_lane);
            break;
    }
}

void LaneGenerator::delete_bottom_lane() {
    int number_of_lanes = this->lanes.size() - 1;
    for (int i = 0; i < number_of_lanes; i++) {
        this->lanes[i] = this->lanes[i+1];
    }
    this->lanes.resize(number_of_lanes);
}

void LaneGenerator::moving_lanes(float moving_speed, bool& isShifting, ResourceManager& resource_manager) {
    for (int i = 0; i < this->lanes.size(); i++) {
        float movement = moving_speed * FRAME_RATE_SECOND;
        this->lanes[i].sprite.move(sf::Vector2f(0, movement));
    }
    
    if (this->lanes[0].sprite.getPosition().y >= BOUNDARY_LANE) {
        if (lanes.size() == SCREEN_HEIGHT / HEIGHT_TITLE) {
            add_lane(resource_manager, -100 + this->lanes[0].sprite.getPosition().y - BOUNDARY_LANE, 0);
        }
        
        if (this->lanes[0].sprite.getPosition().y >= SCREEN_HEIGHT) {
            delete_bottom_lane();
            isShifting = false;
        }
    }
}

int LaneGenerator::counting_lanes() {
    return this->lanes.size();
}

Lane LaneGenerator::operator[](const int index) {
    return this->lanes[index];
}
