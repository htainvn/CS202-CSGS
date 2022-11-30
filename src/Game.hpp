//
//  Game.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "src/Handler.hpp"

#include "src/GameState.hpp"

class Game {
private:
    handler_ptr machine = new Handler;
    
    sf::Clock game_clock = sf::Clock();
    
    void run();
    
    void frame_refresh(float&, float&);
    
public:
    Game();
};

#endif /* Game_hpp */
