//
//  ResourceManager.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/ResourceManager.hpp"

void ResourceManager::load_texture(std::string hash_name, std::string path) {
    sf::Texture texture;
    if (texture.loadFromFile(path)) {
        texture.setSmooth(true);
        this->storage.push_back(make_pair(hash_name, texture));
    }
}

sf::Texture& ResourceManager::get_texture(std::string hash_name) {
    for (int i = 0; i < storage.size(); i++) {
        if (storage[i].first == hash_name) {
            return storage[i].second;
        }
    }
    return storage[0].second;
}
