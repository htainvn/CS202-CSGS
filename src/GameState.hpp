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

class GameState : public State {
private:
    
    int level = 2;
    
    sf::Text count_down;
    
    sf::Text t_lev;
    
    sf::CircleShape light_circle = sf::CircleShape(15.f);
    
    People people;
    
    handler_ptr data;
    
    sf::Clock countingClock = sf::Clock();
    
    LaneGenerator lane_gen;
    
    int isShifting = 0;
    
    bool has_shifted = false;
    
public:
    GameState(handler_ptr _data);
    
    void init(int status);
    void handle_input();
    void update(float dt);
    void draw(float dt);
    void pause();
    void resume();
    bool lost();
    ~GameState();
};

#endif /* GameState_hpp */
