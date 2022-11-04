//
//  GameState.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "GameState.hpp"

GameState::GameState(handler_ptr _data) {
    this->data = _data;
}

void GameState::init() {
    this->data->resource_manager.load_texture("PAVEMENT", PAVEMENT_IMAGE_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_BOTTOMDASH_NORMAL", LEFT_BOTTOMDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_BOTTOMDASH_TOP", LEFT_BOTTOMDASH_TOP_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_FULLDASH_NORMAL", LEFT_FULLDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_NODASH_BOTTOM", LEFT_NODASH_BOTTOM_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_NODASH_NORMAL", LEFT_NODASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_NOLINE", LEFT_NOLINE_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_TOPDASH_BOTTOM", LEFT_TOPDASH_BOTTOM_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_TOPDASH_NORMAL", LEFT_TOPDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_BOTTOMDASH_NORMAL", RIGHT_BOTTOMDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_BOTTOMDASH_TOP", RIGHT_BOTTOMDASH_TOP_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_FULLDASH_NORMAL", RIGHT_FULLDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_NODASH_BOTTOM", RIGHT_NODASH_BOTTOM_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_NODASH_NORMAL", RIGHT_NODASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_NOLINE", RIGHT_NOLINE_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_TOPDASH_BOTTOM", RIGHT_TOPDASH_BOTTOM_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_TOPDASH_NORMAL", RIGHT_TOPDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("RIVER", RIVER_FILE_PATH);
    this->data->resource_manager.load_texture("TRAFFIC_RED", TRAFFIC_SIGN_RED_FILE_PATH);
    this->data->resource_manager.load_texture("TRAFFIC_YELLOW", TRAFFIC_SIGN_YELLOW_FILE_PATH);
    this->data->resource_manager.load_texture("TRAFFIC_GREEN", TRAFFIC_SIGN_GREEN_FILE_PATH);
    
    
    for (int i = 600; i >= 0; i-=100) {
        lane_gen.add_lane(data->resource_manager, i, 0);
    }
}

void GameState::handle_input() {
    sf::Event key_event;
    if (this->data->window.pollEvent(key_event)) {
        switch(key_event.type) {
            case (sf::Event::Closed) :
                this->data->window.close();
                break;
            case (sf::Event::MouseButtonPressed) :
                //if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)) {
                    printf("ok!\n");
                    isShifting = true;
                //}
                //else {
                    
                //}
                break;
        }
    }
}

void GameState::update(float dt) {
    this->lane_gen.moving_lanes(((isShifting) ? SHIFT_MOVING_SPEED : LANE_MOVING_SPEED), isShifting, data->resource_manager);
    
}

void GameState::draw(float dt) {
    this->data->window.clear();
    
    this->data->display_lane(lane_gen);
    
    this->data->window.display();
}

void GameState::pause() {
    
}

void GameState::resume() {
    
}

GameState::~GameState() {
    if (data) {
        delete data;
        data = nullptr;
    }
}
