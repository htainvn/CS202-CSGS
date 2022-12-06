//
//  ThemeController.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 02/12/2022.
//

#include "ThemeController.hpp"

std::string ThemeController::get_random_theme()
{
    
    
    int theme_index = rand() % 4;
    
    switch(theme_index)
    {
        case 0:
            current_theme = "modern";
            break;
        case 1:
            current_theme = "8bit";
            break;
        case 2:
            current_theme = "neon";
            break;
        case 3:
            current_theme = "lava";
            break;
    }

    return current_theme;
    
}

void ThemeController::load()
{
    resource_manager.init(current_theme);
}

std::string ThemeController::get_theme_name()
{
    return current_theme;
}

sf::Texture& ThemeController::get(std::string hash_name, bool dir)
{
    
    return resource_manager.get_texture(hash_name);
}

sf::SoundBuffer& ThemeController::get_buffer(std::string hash_name) {
    return resource_manager.get_sound_buffer(hash_name);
}

void ThemeController::set(std::string _theme)
{
    current_theme = _theme;
}

void ThemeController::add(std::string _theme) { 
    
}

