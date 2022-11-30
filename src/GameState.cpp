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
}

void GameState::init(int status) {
    
    tools->resource_manager.init();
    
    people = new People(this->tools->resource_manager);
    
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
        
        lane_gen->add_lane(PATHWAY_TYPE, Position(0, 600));
        lane_gen->add_lane(PATHWAY_TYPE, Position(0, 500));
        lane_gen->add_lane(PATHWAYLIGHT_TYPE, Position(0, 400));
        lane_gen->add_lane(ROAD_TYPE, Position(0, 300));
        lane_gen->add_lane(PATHWAY_TYPE, Position(0, 200));
        lane_gen->add_lane(PATHWAYLIGHT_TYPE, Position(0, 100));
        lane_gen->add_lane(ROAD_TYPE, Position(0, 0));
        
        lane_gen->add_lane(PATHWAY_TYPE, Position(0, -100));
        lane_gen->add_lane(PATHWAYLIGHT_TYPE, Position(0, -200));
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
                        
                        people->move_right(this->tools->resource_manager);
                        break;
                        
                    case (sf::Keyboard::A):
                    case (sf::Keyboard::Left):
                        
                        people->move_left(this->tools->resource_manager);
                        break;
                        
                    case (sf::Keyboard::S):
                    case (sf::Keyboard::Down):
                        
                        if (people->can_move_down())
                        {
                            people->move_down(this->tools->resource_manager);
                            lane_gen->prev_current(people);
                        }
                        
                        break;
                        
                    case (sf::Keyboard::W):
                        
                        if (people->can_move_forward())
                        {
                            level+=0.8;
                            people->move_forward(this->tools->resource_manager);
                            lane_gen->next_current(people);
                            
                            //if (people->get_position().y < lane_gen->at(2)->position().get_y()){
                            //    ++isShifting;
                            //}
                            //people.move_forward(sf::Vector2f(people.get_position().x, lane_gen[people.lane()+1]->sprite.getPosition().y), this->data->resource_manager);
                            //this->lane_gen.inc_multi_base();
                            //this->lane_gen.set_cutoff(countingClock.getElapsedTime().asMilliseconds());
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

void GameState::update(float dt)
{
    /* update position */
    lane_gen->refactor(level);
    
    /* update level */
    int status = traffic->update();
    
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
    
    check_lost();
}

void GameState::draw(float dt)
{
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

void GameState::pause()
{
    
}

void GameState::resume()
{
    
}

bool GameState::check_lost() 
{
    if (people->touch_border() || lane_gen->at(lane_gen->current())->check_lost()){
        this->tools->window.close();
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
