//
//  ResourceManager.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <stdio.h>

class ResourceManager {
public:
    
    void load_texture(std::string hash_name, std::string path);
    
    sf::Texture& get_texture(std::string hash_name);
    
    void init(std::string theme);
    
private:
    
    std::vector<std::pair<std::string, sf::Texture>> storage;
};

#endif /* ResourceManager_hpp */
