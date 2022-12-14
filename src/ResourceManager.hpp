//
//  ResourceManager.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <filesystem>

class ResourceManager {
public:
    
    void load_texture(std::string hash_name, std::string path);

    void load_sound_buffer(std::string hash_name, std::string path);

    void load_music(std::string current_theme,sf::Music& theme_sound);
    
    sf::Texture& get_texture(std::string hash_name);

    sf::SoundBuffer& get_sound_buffer(std::string hash_name);
    
    void extracted(const std::string &theme);
    
void init();
    
    void load(std::string theme);
    
    std::string autosave_getfilename();
    
private:
    void loadTextureData(const std::string &theme);
    
private:
    
    std::vector<std::pair<std::string, sf::Texture>> storage;
    
    std::vector<std::pair<std::string, sf::Texture>> texture_warehouse;

    std::vector <std::pair<std::string, sf::SoundBuffer>> sound_storage;

};

#endif /* ResourceManager_hpp */
