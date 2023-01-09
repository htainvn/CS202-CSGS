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
#include "Position.hpp"
#include "src/ResourceManager.hpp"
#include "src/definition_library.hpp"

class ThemeController {
public:
    
    ThemeController() {
        resource_manager.init();
    }
    
    std::string get_random_theme();
    
    void load();
    
    std::string get_theme_name();
    
    sf::Texture& get(std::string hash_name, bool dir = 0);
    
    void set(std::string _theme);

    sf::SoundBuffer& get_buffer(std::string hash_name);
    
    void add(std::string _theme);
    
    Position getSize(std::string type);
    
    std::string autosave_getfilename();

    void play_music();

    void stop_music();
    
private:
    
    ResourceManager resource_manager;
    
    std::string current_theme = "";

    sf::Music theme_sound;
    
};

#endif /* ThemeController_hpp */
