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
    resource_manager.load(current_theme);
    resource_manager.load_music(current_theme,theme_sound);
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

Position ThemeController::getSize(std::string type) {
    return Position(get(type).getSize().x, get(type).getSize().y);
}

std::string ThemeController::autosave_getfilename() {
    std::string path = WORKING_DIR + "/datagame";
    for (int i = 0; i <= 5; i++) {
        bool check = true;
        std::string filename = "data_saved_" + std::to_string(i);
        for (const auto & entry : std::filesystem::directory_iterator(path))
        {
            if (entry.path() == path + "/" + filename + ".txt") {
                check = false;
                break;
            }
        }
        if (check) return filename;
    }
    return "Nothing_left";
}

void ThemeController::play_music() {
    theme_sound.play();
}

void ThemeController::stop_music() {
    theme_sound.stop();
}
