//
//  GameState.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/GameState.hpp"
#include <fstream>

GameState::GameState(handler_ptr _data) {
    this->data = _data;
}

void GameState::init(int status) {
    this->data->resource_manager.load_texture("PAVEMENT", PAVEMENT_IMAGE_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_BOTTOMDASH_NORMAL", LEFT_BOTTOMDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_BOTTOMDASH_TOP", LEFT_BOTTOMDASH_TOP_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_FULLDASH_NORMAL", LEFT_FULLDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_NODASH_BOTTOM", LEFT_NODASH_BOTTOM_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_NODASH_NORMAL", LEFT_NODASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_NODASH_TOP", LEFT_NODASH_TOP_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_NOLINE", LEFT_NOLINE_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_TOPDASH_BOTTOM", LEFT_TOPDASH_BOTTOM_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_LEFT_TOPDASH_NORMAL", LEFT_TOPDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_BOTTOMDASH_NORMAL", RIGHT_BOTTOMDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_BOTTOMDASH_TOP", RIGHT_BOTTOMDASH_TOP_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_FULLDASH_NORMAL", RIGHT_FULLDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_NODASH_BOTTOM", RIGHT_NODASH_BOTTOM_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_NODASH_NORMAL", RIGHT_NODASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_NODASH_TOP", RIGHT_NODASH_TOP_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_NOLINE", RIGHT_NOLINE_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_TOPDASH_BOTTOM", RIGHT_TOPDASH_BOTTOM_FILE_PATH);
    this->data->resource_manager.load_texture("ROAD_RIGHT_TOPDASH_NORMAL", RIGHT_TOPDASH_NORMAL_FILE_PATH);
    this->data->resource_manager.load_texture("RIVER", RIVER_FILE_PATH);
    this->data->resource_manager.load_texture("TRAFFIC_RED", TRAFFIC_SIGN_RED_FILE_PATH);
    this->data->resource_manager.load_texture("TRAFFIC_YELLOW", TRAFFIC_SIGN_YELLOW_FILE_PATH);
    this->data->resource_manager.load_texture("TRAFFIC_GREEN", TRAFFIC_SIGN_GREEN_FILE_PATH);
    
    this->data->resource_manager.load_texture("MARIO_FORWARD", MARIO_FORWARD_FILE_PATH);
    this->data->resource_manager.load_texture("MARIO_DOWNWARD", MARIO_DOWNWARD_FILE_PATH);
    this->data->resource_manager.load_texture("MARIO_RIGHT", MARIO_RIGHT_FILE_PATH);
    this->data->resource_manager.load_texture("MARIO_LEFT", MARIO_LEFT_FILE_PATH);

    //people
    this->people = People(this->data->resource_manager);
    //
    
    
    if (status == 0) {
        //initialization
        
        this->lane_gen.add_lane(this->data->resource_manager, 600, 0);
        this->lane_gen.add_lane(this->data->resource_manager, 500, 0);
        this->lane_gen.add_lane(this->data->resource_manager, 400, 1);
        this->lane_gen.add_lane(this->data->resource_manager, 300, 2);
        this->lane_gen.add_lane(this->data->resource_manager, 200, 0);
        this->lane_gen.add_lane(this->data->resource_manager, 100, 1);
        this->lane_gen.add_lane(this->data->resource_manager, 0, 2);
        
        this->lane_gen.add_prediction(this->data->resource_manager, 0);
        this->lane_gen.add_prediction(this->data->resource_manager, 1);
        
        this->lane_gen.set_level(3, 0, 1);
        
        //end of initialization
    }
    else {
        //load game
        std::ifstream fin(WORKING_DIR + "/datagame/data.txt");
        int x, y; fin >> x >> y;
        this->people.go_to_position(x, y);
        
        int n; fin >> n;
        for (int i = 0; i < n; i++) {
            int type_of_lane; fin >> type_of_lane;
            float l_y; fin >> l_y;
            lane_gen.add_lane(data->resource_manager, l_y, type_of_lane);
            switch(type_of_lane) {
                case 2:
                {
                    int _pos, _dir, _bot, _top; fin >> _pos >> _dir >> _bot >> _top;
                    lane_gen[lane_gen.counting_lanes()-1]->change_position(_pos);
                    lane_gen[lane_gen.counting_lanes()-1]->change_dir(_dir);
                    lane_gen[lane_gen.counting_lanes()-1]->change_bottom_type(_bot);
                    lane_gen[lane_gen.counting_lanes()-1]->change_top_type(_top);
                    lane_gen[lane_gen.counting_lanes()-1]->change_texture(data->resource_manager);
                    int nV; fin >> nV;
                    for (int j = 0; j < nV; j++) {
                        float _posV; fin >> _posV;
                        Vehicle* new_veh = new Vehicle(data->resource_manager);
                        new_veh->go_to_position(_posV);
                        lane_gen[lane_gen.counting_lanes()-1]->add_vehicle(new_veh);
                    }
                    break;
                }
                case 3:
                {
                    int nL; fin >> nL;
                    for (int j = 0; j < nL; j++) {
                        float _posL; fin >> _posL;
                        Log* new_log = new Log(data->resource_manager);
                        new_log->go_to_position(_posL);
                        lane_gen[lane_gen.counting_lanes()-1]->add_log(new_log);
                    }
                    fin >> nL;
                    for (int j = 0; j < nL; j++) {
                        float _posL; fin >> _posL;
                        Animal* new_animal = new Animal(data->resource_manager);
                        new_animal->go_to_position(_posL);
                        lane_gen[lane_gen.counting_lanes()-1]->add_animal(new_animal);
                    }
                    break;
                }
            }
        }
        for (int i = 0; i < 1; i++) {
            int type_of_lane; fin >> type_of_lane;
            lane_gen.add_prediction(data->resource_manager, type_of_lane);
            int _pos, _dir, _bot, _top; fin >> _pos >> _dir >> _bot >> _top;
            lane_gen.get_prediction(i)->change_position(_pos);
            lane_gen.get_prediction(i)->change_dir(_dir);
            lane_gen.get_prediction(i)->change_bottom_type(_bot);
            lane_gen.get_prediction(i)->change_bottom_type(_top);
            lane_gen.get_prediction(i)->change_texture(data->resource_manager);
        }
        long long ltc; fin >> ltc;
        while (countingClock.getElapsedTime().asSeconds() < ltc) {}
        //end
    }
}

void GameState::handle_input() {
    sf::Event key_event;
    if (this->data->window.pollEvent(key_event)) {
        switch(key_event.type) {
            case (sf::Event::Closed) :
                this->data->window.close();
                break;
            case (sf::Event::KeyPressed):
            {
                switch (key_event.key.code) {
                    case (sf::Keyboard::D):
                        this->people.move_right(this->data->resource_manager);
                        break;
                    case (sf::Keyboard::A):
                        this->people.move_left(this->data->resource_manager);
                        break;
                    case (sf::Keyboard::S):
                        this->people.move_down(this->data->resource_manager);
                        break;
                    case (sf::Keyboard::W):
                        isShifting = true;
                        break;
                    default:
                        break;
                }
            }
                break;
        }
    }
}

void GameState::update(float dt) {
    bool catchShifting = isShifting;
    
    this->lane_gen.updating(((isShifting) ? SHIFT_MOVING_SPEED : LANE_MOVING_SPEED), countingClock, isShifting, data->resource_manager, (countingClock.getElapsedTime().asSeconds() >= 5));
    people.move(sf::Vector2f(0, ((isShifting) ? SHIFT_MOVING_SPEED : LANE_MOVING_SPEED)*FRAME_RATE_SECOND));
    
    if (catchShifting) {
        people.get_sprite().setPosition(sf::Vector2f(people.get_sprite().getPosition().x, lane_gen[2]->sprite.getPosition().y));
    }
    
    for (int i = 0; i < lane_gen.counting_lanes(); i++) {
        lane_gen[i]->adjust_objects();
    }
    if (countingClock.getElapsedTime().asSeconds() >= 6) {
        for (int i = 0; i < lane_gen.counting_lanes(); i++) {
            lane_gen[i]->update_traffic(this->data->resource_manager, 0, countingClock);
        }
    }
    if (countingClock.getElapsedTime().asSeconds() > 15) {
        for (int i = 0; i < lane_gen.counting_lanes(); i++) {
            lane_gen[i]->update_traffic(this->data->resource_manager, 1, countingClock);
        }
        countingClock.restart();
    }
}

void GameState::draw(float dt) {
    this->data->window.clear();
    
    this->data->display_lane(lane_gen);
    
    this->data->window.draw(this->people.get_sprite());
    
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