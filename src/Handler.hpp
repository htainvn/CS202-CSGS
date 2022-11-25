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
#include "src/ResourceManager.hpp"

class Handler {
public:
    
    StateManager state_manager;
    
    ResourceManager resource_manager;
    
    sf::RenderWindow window;
    
    Handler() {
        this->state_manager = StateManager();
    }
    
};

#endif /* Handler_h */
