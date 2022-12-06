//
//  ThemeController.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 02/12/2022.
//

#ifndef ThemeController_hpp
#define ThemeController_hpp

#include <string>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "src/ResourceManager.hpp"

class ThemeController {
public:
    
    std::string get_random_theme();
    
    void load();
    
    std::string get_theme_name();
    
    sf::Texture& get(std::string hash_name, bool dir = 0);
    
    void set(std::string _theme);

    sf::SoundBuffer& get_buffer(std::string hash_name);
    
    void add(std::string _theme);
    
private:
    
    ResourceManager resource_manager;
    
    std::string current_theme = "";
    
};

#endif /* ThemeController_hpp */
