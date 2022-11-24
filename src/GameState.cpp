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
    // road
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
    // people
    this->data->resource_manager.load_texture("MARIO_FORWARD", MARIO_FORWARD_FILE_PATH);
    this->data->resource_manager.load_texture("MARIO_DOWNWARD", MARIO_DOWNWARD_FILE_PATH);
    this->data->resource_manager.load_texture("MARIO_RIGHT", MARIO_RIGHT_FILE_PATH);
    this->data->resource_manager.load_texture("MARIO_LEFT", MARIO_LEFT_FILE_PATH);
    // vehicle
    this->data->resource_manager.load_texture("CL_0", CL_0);
    this->data->resource_manager.load_texture("CL_1", CL_1);
    this->data->resource_manager.load_texture("CL_2", CL_2);
    this->data->resource_manager.load_texture("CL_3", CL_3);
    this->data->resource_manager.load_texture("CL_4", CL_4);
    this->data->resource_manager.load_texture("CL_5", CL_5);
    this->data->resource_manager.load_texture("CL_6", CL_6);
    this->data->resource_manager.load_texture("CL_7", CL_7);
    this->data->resource_manager.load_texture("CL_8", CL_8);
    this->data->resource_manager.load_texture("CR_0", CR_0);
    this->data->resource_manager.load_texture("CR_1", CR_1);
    this->data->resource_manager.load_texture("CR_2", CR_2);
    this->data->resource_manager.load_texture("CR_3", CR_3);
    this->data->resource_manager.load_texture("CR_4", CR_4);
    this->data->resource_manager.load_texture("CR_5", CR_5);
    this->data->resource_manager.load_texture("CR_6", CR_6);
    this->data->resource_manager.load_texture("CR_7", CR_7);
    this->data->resource_manager.load_texture("CR_8", CR_8);

    this->data->resource_manager.load_texture("CROC_LEFT",CROC_LEFT_FILE_PATH );
    this->data->resource_manager.load_texture("CROC_RIGHT",CROC_RIGHT_FILE_PATH );
    this->data->resource_manager.load_texture("HIPPO_LEFT",HIPPO_LEFT_FILE_PATH );
    this->data->resource_manager.load_texture("HIPPO_RIGHT",HIPPO_RIGHT_FILE_PATH );


    //people
    this->people = People(this->data->resource_manager);
    
    //font
    this->font = new sf::Font();
    if (!this->font->loadFromFile(FONT_PATH_FILE)) {
        std::cout << "Loi!\n";
    }
    //
    
    //mini-light
    light_circle.setFillColor(sf::Color::Red);
    light_circle.setPosition(sf::Vector2f(10, 10));
    
    count_down.setPosition(sf::Vector2f(50, 13));
    count_down.setFont(*font);
    count_down.setCharacterSize(20);
    count_down.setStyle(sf::Text::Regular);
    //
    
    //show level
    t_lev.setPosition(sf::Vector2f(700, 13));
    t_lev.setFont(*font);
    t_lev.setCharacterSize(20);
    t_lev.setStyle(sf::Text::Regular);
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
        
        this->lane_gen.set_cutoff(countingClock.getElapsedTime().asMilliseconds());
        
        //end of initialization
    }
    else {
        /*
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
                        lane_gen[lane_gen.counting_lanes() - 1]->add_animal(new_animal);
                        
                    }
                    //break;
                //}
            //}
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
        //end */
    }
}

void GameState::handle_input() {
    sf::Event key_event;
    if (this->data->window.pollEvent(key_event)) {
        switch(key_event.type) {
            case (sf::Event::Closed):
                this->data->window.close();
                break;
            case (sf::Event::KeyPressed):
            {
                switch (key_event.key.code) {
                    case (sf::Keyboard::D):
                        this->people.move_right(this->data->resource_manager);
                        break;
                    case (sf::Keyboard::Right):
                        this->people.move_right(this->data->resource_manager);
                        break;
                    case (sf::Keyboard::A):
                        this->people.move_left(this->data->resource_manager);
                        break;
                    case (sf::Keyboard::Left):
                        this->people.move_left(this->data->resource_manager);
                        break;
                    case (sf::Keyboard::S):
                        this->people.move_down(this->data->resource_manager);
                        break;
                    case (sf::Keyboard::Down):
                        this->people.move_down(this->data->resource_manager);
                        break;
                    case (sf::Keyboard::W):
                        has_shifted = false;
                        if (people.can_move_forward()) {
                            if (people.get_position().y < lane_gen[2]->sprite.getPosition().y){
                                ++isShifting;
                            }
                            people.move_forward(sf::Vector2f(people.get_position().x, lane_gen[people.lane()+1]->sprite.getPosition().y), this->data->resource_manager);
                            this->lane_gen.inc_multi_base();
                            this->lane_gen.set_cutoff(countingClock.getElapsedTime().asMilliseconds());
                        }
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
    //camera moving
    if (isShifting < 4){
        has_shifted = 1;
    }
    
    float mov_spd = ((isShifting < 4) ? (isShifting) : (isShifting + 1)) * SHIFT_MOVING_SPEED;
    
    if (countingClock.getElapsedTime().asMilliseconds() > this->lane_gen.get_cutoff() + 300) mov_spd = 3.0f * SHIFT_MOVING_SPEED;
        
    this->lane_gen.updating(((isShifting) ? mov_spd : LANE_MOVING_SPEED), countingClock, isShifting, has_shifted, data->resource_manager, (countingClock.getElapsedTime().asSeconds() >= 5), level);
    
    people.move(sf::Vector2f(0, ((isShifting) ? mov_spd : LANE_MOVING_SPEED)*FRAME_RATE_SECOND));
    
    t_lev.setString("Level: " + std::to_string(level/2));
    
    if (countingClock.getElapsedTime().asMilliseconds() > this->lane_gen.get_cutoff() + 300) {
        this->lane_gen.reset_base();
    }
    //end here
    
    //adjust all objects on the lanes
    for (int i = 0; i < lane_gen.counting_lanes(); i++) {
        lane_gen[i]->adjust_objects();
    }
    //end here
    
    //manage the traffic light
    int cnt_time;
    while ((cnt_time = countingClock.getElapsedTime().asSeconds()) > GREEN_TIME_END) {
        countingClock.restart();
    }
    if (cnt_time >= RED_TIME_END) {
        
        if (cnt_time >= YELLOW_TIME_START) light_circle.setFillColor(sf::Color::Yellow);
        else light_circle.setFillColor(sf::Color::Green);
        
        for (int i = 0; i < lane_gen.counting_lanes(); i++) {
            lane_gen[i]->update_traffic(this->data->resource_manager, cnt_time);
        }
        
        count_down.setString(std::to_string(GREEN_TIME_END - cnt_time));
    }
    else {
        
        light_circle.setFillColor(sf::Color::Red);
        
        for (int i = 0; i < lane_gen.counting_lanes(); i++) {
            lane_gen[i]->update_traffic(this->data->resource_manager, cnt_time);
        }
        
        count_down.setString(std::to_string(RED_TIME_END - cnt_time));
    }
    //end here
}

void GameState::draw(float dt) {
    
    this->data->window.clear();
    
    this->data->display_lane(lane_gen);
    
    if (has_shifted) this->data->window.draw(this->people.get_sprite());
    
    this->data->window.draw(light_circle);
    
    this->data->window.draw(t_lev);
    
    this->data->window.draw(count_down);
    
    this->data->window.display();
}

void GameState::pause() {
    
}

void GameState::resume() {
    
}

bool GameState::check_lost() 
{
    if (this->people.touch_border()){ // if collision, if fall into water are being missed
        this->data->window.close();
        return true;
    }
    return true;
}

GameState::~GameState() {
    if (data) {
        delete data;
        data = nullptr;
    }
    if (font) {
        delete font;
        font = nullptr;
    }
}
