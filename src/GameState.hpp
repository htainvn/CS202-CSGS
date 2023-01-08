//
//  GameState.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef GameState_hpp
#define GameState_hpp

#include <stdio.h>

#include <SFML/Graphics.hpp>
#include "src/State.hpp"
#include "src/Handler.hpp"
#include "src/LaneGenerator.hpp"
#include "src/definition_library.hpp"
#include "src/People.hpp"
#include "src/Traffic.hpp"
#include "src/LostState.hpp"
//#include "src/GamePauseState.hpp"
#include <fstream>

class GameState : public State {
    
public:
    
    GameState() = default;
    
    GameState(handler_ptr _data);
    
    GameState(const GameState& other);
    
    virtual ~GameState();
    
    void init(int status);
    
    void handle_input();
    
    virtual void create_new();
    
    void load_game(std::string filename);
    
    void update(float dt);
    
    void draw(float dt);
    
    void pause();
    
    void resume();

    void save();
    
    bool check_lost();
    
    void extracted();
    
    void pre_lost();
    
    void record();
    
    
    
protected:
    
    float level = 0;
    
    sf::Text t_lev;
    
    Traffic* traffic;
    
    People* people = nullptr;
    
    handler_ptr tools;
    
    LaneFactory* lane_gen;
    
    bool is_pause = false;
    
    int lost_count = 0;
    
    int mario_lost_count = 0;
    
    bool is_TouchBounder = false;
    
    sf::View view;
    
private:
    void earthquake();
    
    void zoom_in();
    
    void save_record();
};

#endif /* GameState_hpp */
