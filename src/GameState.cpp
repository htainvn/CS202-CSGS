//
//  GameState.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/GameState.hpp"
#include "src/Position.hpp"
#include <fstream>

GameState::GameState(handler_ptr _tools) : tools(_tools) {
    lane_gen = new LaneFactory(_tools);
    
    traffic = new Traffic(_tools);
    
    tools->theme_controller.get_random_theme();
    
    tools->theme_controller.load();
}

void GameState::init(int status) {
    
    people = new People(tools);
    
    font = new sf::Font();
    font->loadFromFile(FONT_PATH_FILE);
    
    traffic->init(font);
    
    //show level
    t_lev.setPosition(sf::Vector2f(700, 13));
    t_lev.setFont(*font);
    t_lev.setCharacterSize(20);
    t_lev.setStyle(sf::Text::Regular);
    //
    
    if (status == 0) {
        //initialization
        
        lane_gen->add_lane(PATHWAY_TYPE, Position(0, 600), Level(1, 3, 1));
        lane_gen->add_lane(PATHWAY_TYPE, Position(0, 500), Level(1, 2, 1));
        lane_gen->add_lane(PATHWAYLIGHT_TYPE, Position(0, 400), Level(1, 1, 1));
        lane_gen->add_lane(ROAD_TYPE, Position(0, 300), Level(1, 0, 1));
        lane_gen->add_lane(PATHWAY_TYPE, Position(0, 200), Level(2, 2, 1));
        lane_gen->add_lane(PATHWAYLIGHT_TYPE, Position(0, 100), Level(2, 1, 1));
        lane_gen->add_lane(ROAD_TYPE, Position(0, 0), Level(2, 0, 1));
        
        lane_gen->add_lane(PATHWAY_TYPE, Position(0, -100), Level(3, 2, 1));
        lane_gen->add_lane(PATHWAYLIGHT_TYPE, Position(0, -200), Level(3, 1, 1));
    }
    else
    {
    }
    
    lane_gen->at(2)->set_current(people);
    people->set_current_lane(2);
    
}

void GameState::handle_input() {
    sf::Event key_event;
    
    if (this->tools->window.pollEvent(key_event))
    {
        
        switch(key_event.type)
        {
                
            case (sf::Event::Closed):
                
                this->tools->window.close();
                break;
                
            case (sf::Event::KeyPressed):
            {
                switch (key_event.key.code) {
                        
                    case (sf::Keyboard::D):
                    case (sf::Keyboard::Right):
                        people->start_movement(1);
                        people->move_right();
                        lane_gen->horizontal_movement(people, 1);
                        break;
                        
                    case (sf::Keyboard::A):
                    case (sf::Keyboard::Left):
                        people->start_movement(2);
                        people->move_left();
                        lane_gen->horizontal_movement(people, 0);
                        break;
                        
                    case (sf::Keyboard::S):
                    case (sf::Keyboard::Down):
                        people->start_movement(3);
                        people->move_down();
                        lane_gen->prev_current(people);
                        break;
                    
                    case (sf::Keyboard::Up):
                    case (sf::Keyboard::W):
                        
                        if (people->can_move_forward())
                        {
                            people->start_movement(0);
                            level+=0.8;
                            people->move_forward();
                            lane_gen->next_current(people);
                            //if (people->get_position().y < lane_gen->at(2)->position().get_y()){
                            //    ++isShifting;
                            //}
                            //people.move_forward(sf::Vector2f(people.get_position().x, lane_gen[people.lane()+1]->sprite.getPosition().y), this->data->resource_manager);
                            //this->lane_gen.inc_multi_base();
                            //this->lane_gen.set_cutoff(countingClock.getElapsedTime().asMilliseconds());
                        }
                        
                        break;
                    case (sf::Keyboard::P):
                        pause();
                    default:
                        break;
                }
            }
            break;
        }
    }
}

void GameState::update(float dt)
{
    if(!is_pause) {
        /* update position */
        lane_gen->refactor(level);
        
        /* update level */
        int status = traffic->update();
        
        int return_code = people->update();
        
        switch(status)
        {
            case 0:
                lane_gen->stop();
                break;
            case 1:
                lane_gen->slowdown();
                break;
            case 2:
                lane_gen->run();
                break;
        }
        
        /* update level */
        std::string t = "Level: " + std::to_string(lane_gen->at(lane_gen->current())->level());
        
        if (t.length() > t_lev.getString().getSize() || t > t_lev.getString()) t_lev.setString(t);
        
        if (lost_count || check_lost())
        {
            lost_count = ((lost_count) ? lost_count-1 : 1000);
            
            people->lost();
            
            if (lost_count) pre_lost();
            else {
                tools->window.create(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "CROSSING MODE", sf::Style::Close);
                tools->state_manager.receive_replace_request(new LostMenu(tools));
            }
        }
    }
    
    /* update level */
    std::string t = "Level: " + std::to_string(lane_gen->at(lane_gen->current())->level());
    
    if (t.length() > t_lev.getString().getSize() || t > t_lev.getString()) {
        t_lev.setString(t);
    }
}

void GameState::draw(float dt)
{
    if (is_pause == false){
        tools->window.clear();
        
        for (int i = 8; i >= 0; i--)
        {
            if (!lane_gen->at(i)->out_scr())
            {
                lane_gen->at(i)->draw();
            }
        }
        tools->window.draw(people->get_sprite());
        
        tools->window.draw(t_lev);
        
        traffic->draw();
        
        tools->window.display();
    }
}

void GameState::pause()
{
    if (is_pause == true){
        resume();
        is_pause = false;
    }
    else is_pause = true;
}

void GameState::resume()
{
    is_pause = false;
}

bool GameState::check_lost() 
{
    if (people->touch_border() || lane_gen->at(lane_gen->current())->check_lost()){
        return true;
    }
    return false;
}

GameState::~GameState() {
    if (tools) {
        delete tools;
        tools = nullptr;
    }
    if (font) {
        delete font;
        font = nullptr;
    }
    if (lane_gen) {
        delete lane_gen;
        lane_gen = nullptr;
    }
}

void GameState::load_game(std::string filename)
{
    std::ifstream fin; fin.open(filename);
    
    // #theme loading# //
    tools->load_theme(fin);
    
    // #lane loading# //
    lane_gen->loading(fin);
    
    // #people loading# //
    people->loading(fin);
    
    fin.close();
}

void GameState::save(std::string filename) {

    std::ofstream fout(DATA_FILE_PATH + filename + ".txt");

    fout << tools->theme_controller.get_theme_name() << std::endl;

    lane_gen->save(fout);

    fout.close();
}

void GameState::pre_lost()
{
    view.setCenter(sf::Vector2f(people->get_position().x + 10, people->get_position().y + 30));
    view.setSize(sf::Vector2f(100, 100));
    view.zoom(0.8 + 0.002 * lost_count); //transition from 1 to 0.5f
    tools->window.setView(view);
}
