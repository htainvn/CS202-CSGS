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
    
    sf::Texture& get_texture(std::string hash_name);

    sf::SoundBuffer& get_sound_buffer(std::string hash_name);
    
    void init(std::string theme);
    
    std::string autosave_getfilename();
    
private:
    
    std::vector<std::pair<std::string, sf::Texture>> storage;

    std::vector <std::pair<std::string, sf::SoundBuffer>> sound_storage;
};

#endif /* ResourceManager_hpp */
