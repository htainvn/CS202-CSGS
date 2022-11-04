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

class GameState : public State {
private:
    handler_ptr data;
    
    sf::Clock countingClock = sf::Clock();
    
    LaneGenerator lane_gen;
    
    bool isShifting = false;
    
public:
    GameState(handler_ptr _data);
    
    void init();
    void handle_input();
    void update(float dt);
    void draw(float dt);
    
    void pause();
    void resume();
    
    ~GameState();
};

#endif /* GameState_hpp */
