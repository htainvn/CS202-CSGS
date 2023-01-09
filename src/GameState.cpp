//
//  GameState.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/GameState.hpp"
#include "src/Position.hpp"
#include "src/GamePauseState.hpp"
#include <fstream>

GameState::GameState(handler_ptr _tools) : tools(_tools)
{
    lane_gen = new LaneFactory(_tools);
    
    traffic = new Traffic(_tools);
    
    tools->theme_controller.get_random_theme();
    
    tools->theme_controller.load();

    tools->theme_controller.play_music();
    
    sf::View defaultView;
    defaultView.setCenter(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
    defaultView.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    
    tools->window.setView(defaultView);
}

GameState::GameState(const GameState& other)
{
    *this = other;
    lane_gen = new LaneFactory(*other.lane_gen);
    traffic = new Traffic(*other.traffic);
    people = new People(*other.people);
    font = new Font (*other.font);
}

void GameState::init(int status) {
    
    people = new People(tools);
    
    font = new sf::Font();
    
    font->loadFromFile(FONT_PATH_FILE);
    
    traffic->init(font);
    
    //show level
    t_lev.setPosition(sf::Vector2f(SCREEN_WIDTH - 100, 13));
    t_lev.setFont(*font);
    t_lev.setCharacterSize(50);
    t_lev.setStyle(sf::Text::Regular);
        
    create_new();
    
}

void GameState::handle_input() {
    sf::Event key_event;
    
    if (this->tools->window.pollEvent(key_event))
    {
        switch(key_event.type)
        {
            case (sf::Event::Closed):
            {
                save();
                this->tools->window.close();
                break;
            }
            case (sf::Event::KeyPressed):
            {
                switch (key_event.key.code) {
                        
                    case (sf::Keyboard::D):
                    case (sf::Keyboard::Right):
                        people->moving();
                        people->start_movement(1);
                        people->move_right((lane_gen->at(lane_gen->current()))->type());
                        break;
                    case (sf::Keyboard::A):
                    case (sf::Keyboard::Left):
                        people->moving(); //change moving attribute in people class to true, in order to prevent the function abjust_object in log class run automatically, then we get rid of the position of people is not updated after moving.
                        people->start_movement(2);
                        people->move_left((lane_gen->at(lane_gen->current()))->type());
                        break;
                    case (sf::Keyboard::S):
                    case (sf::Keyboard::Down):
                        people->moving();
                        people->start_movement(3);
                        people->move_down();
                        lane_gen->prev_current(people);
                        break;
                    case (sf::Keyboard::Up):
                    case (sf::Keyboard::W):
                        if (people->can_move_forward())
                        {
                            people->moving();
                            people->start_movement(0);
                            level+=0.8;
                            people->move_forward();
                            lane_gen->next_current(people);
                        }
                        break;
                    case (sf::Keyboard::P):
                        pause();
                        break;
                    case (sf::Keyboard::Escape):
                    {
                        save();
                        this->tools->window.close();
                        break;
                    }
                    default:
                        break;
                }
            }
            default:
                break;
        }
    }
}

void GameState::update(float dt)
{
    
    if (people->is_alive())
    {
        /* update position */
        lane_gen->refactor(level);
        
        /* update level */
        int status = traffic->update(is_pause);
        
        int return_code = people->update();
        if (dt == -1|| return_code == 1 || return_code == 2) lane_gen->horizontal_movement(people, return_code);
            
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
        std::string t = std::to_string(lane_gen->at(lane_gen->current())->level());
        
        if (t.length() > t_lev.getString().getSize() || t > t_lev.getString()) t_lev.setString(t);
        if(check_lost()) people->lost();
    }
    else {
        if (lost_count || !people->is_alive()) {
            lost_count = ((lost_count) ? lost_count-1 : 1000);
            
            if (lost_count) pre_lost();
            else {
                tools->state_manager.receive_replace_request(new LostMenu(tools));
            }
        }
    }
}

void GameState::draw(float dt)
{
    if (is_pause == false) {
        
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
    is_pause = true;
    tools->state_manager.receive_add_request(new GamePauseState(this->tools, new GameStateScreen(this)));
}

void GameState::resume()
{
    update(0);
    //tools->theme_controller.play_music();
    is_pause = false;
}

bool GameState::check_lost() 
{
    if (lane_gen->at(lane_gen->current())->check_lost()){
        return true;
    }
    if (people->touch_border()){
        is_TouchBounder = true;
        return true;
    }
    return false;
}

GameState::~GameState()
{
    tools->theme_controller.stop_music();

    /*if (people){
        delete people;
        people = nullptr;
    }*/
    
    if (font) {
        delete font;
        font = nullptr;
    }
    
    if (lane_gen)  {
        delete lane_gen;
        lane_gen = nullptr;
    }
    
    if (traffic) {
        delete traffic;
        traffic = nullptr;
    }
    
}

void GameState::create_new() {
    lane_gen->add_lane(PATHWAY_TYPE, Position(-500, 600), Level(1, 3, 1));
    lane_gen->add_lane(PATHWAY_TYPE, Position(-500, 500), Level(1, 2, 1));
    lane_gen->add_lane(PATHWAYLIGHT_TYPE, Position(-500, 400), Level(1, 1, 1));
    lane_gen->add_lane(ROAD_TYPE, Position(-500, 300), Level(1, 0, 1));
    lane_gen->add_lane(PATHWAY_TYPE, Position(-500, 200), Level(2, 2, 1));
    lane_gen->add_lane(PATHWAYLIGHT_TYPE, Position(-500, 100), Level(2, 1, 1));
    lane_gen->add_lane(ROAD_TYPE, Position(-500, 0), Level(2, 0, 1));
    lane_gen->add_lane(PATHWAY_TYPE, Position(-500, -100), Level(3, 2, 1));
    lane_gen->add_lane(PATHWAYLIGHT_TYPE, Position(-500, -200), Level(3, 1, 1));
    
    lane_gen->at(2)->set_current(people);
    people->set_current_lane(2);
}

void GameState::load_game(std::string filename)
{
    
}

void GameState::save() {

    std::string filename = tools->theme_controller.autosave_getfilename();
    
    if (filename == "Nothing_left") {
        
        return;
    }
    
    std::ofstream fout(DATA_FILE_PATH + filename + ".txt");

    fout << tools->theme_controller.get_theme_name() << "\n";
    
    traffic->save(fout);
    
    people->save(fout);

    lane_gen->save(fout);
    
    fout << level << " " << is_pause << " " << lost_count << " " << mario_lost_count << " " << is_TouchBounder << "\n";

    fout.close();
}

void GameState::earthquake() {
    view.setCenter(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
    view.setSize(sf::Vector2f(700, 700));
    view.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    int temp = rand() % 4;
    switch (temp) {
        case 0:
            view.move(sf::Vector2f(lost_count % 10,lost_count % 10));
            break;
        case 1:
            view.move(sf::Vector2f(-lost_count % 10,lost_count % 10));
            break;
        case 2:
            view.move(sf::Vector2f(lost_count % 10,-lost_count % 10));
            break;
        case 3:
            view.move(sf::Vector2f(-lost_count % 10,-lost_count % 10));
            break;
        default:
            break;
    }
}

void GameState::zoom_in() {
    view.setCenter(sf::Vector2f(people->get_position().x + 10, people->get_position().y + 30));
    view.setSize(sf::Vector2f(350, 350));
    view.zoom(0.99 + 0.0001 * lost_count);
}

void GameState::save_record() {
    std::ifstream fin(WORKING_DIR + "/datagame/Recorder.txt");
    int MaxLevel = 0;
    fin >> MaxLevel;
    fin.close();
    std::string str = t_lev.getString();
    if (MaxLevel < stoi(str))
        MaxLevel = stoi(str);
    std::ofstream fout(WORKING_DIR + "/datagame/Recorder.txt");
    fout << MaxLevel;
    fout.close();
}

void GameState::pre_lost()
{
    save_record();
    
    if (!is_TouchBounder)
    {
        zoom_in(); //transition from 1 to 0.5f
    }
    else {
        earthquake();
    }
    tools->window.setView(view);
}
