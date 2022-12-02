//
//  Handler.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Handler_h
#define Handler_h

#include <SFML/Graphics.hpp>
#include "src/StateManager.hpp"
#include "src/ThemeController.hpp"

class Handler {
public:
    
    StateManager state_manager;
    
    ThemeController theme_controller;
    
    sf::RenderWindow window;
    
    Handler() {
        this->state_manager = StateManager();
    }
    
};

#endif /* Handler_h */
