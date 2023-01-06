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
#include <fstream>

class Handler {
public:
    
    const int car_number = 9;
    const int MAX_SPEED = 36; // maximum speed
    sf::RenderWindow window;
    
    StateManager state_manager;
    
    ThemeController theme_controller;
    
    Handler() {
        this->state_manager = StateManager();
    }
    
    void load_theme(std::ifstream& fin)
    {
        std::string _theme; fin >> _theme;
        theme_controller.set(_theme);
        theme_controller.load();
    }
    
};

#endif /* Handler_h */
