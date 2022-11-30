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

class GameState : public State {
private:
    
    float level = 0;
    
    sf::Text t_lev;
    
    Traffic* traffic;
    
    People* people = nullptr;
    
    handler_ptr tools;
    
    LaneFactory* lane_gen;
    
public:
    
    GameState(handler_ptr _data);
    
    void init(int status);
    
    void handle_input();
    
    void update(float dt);
    
    void draw(float dt);
    
    void pause();
    
    void resume();
    
    bool check_lost();
    
    ~GameState();
};

#endif /* GameState_hpp */
