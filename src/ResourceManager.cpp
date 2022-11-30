//
//  ResourceManager.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/definition_library.hpp"
#include "src/ResourceManager.hpp"

void ResourceManager::load_texture(std::string hash_name, std::string path) {
    sf::Texture texture;
    if (texture.loadFromFile(path)) {
        texture.setSmooth(true);
        this->storage.push_back(make_pair(hash_name, texture));
    }
    else {
        std::cout << "error at: " << path << "\n";
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

void ResourceManager::init() { 
    load_texture("PAVEMENT", PAVEMENT_IMAGE_FILE_PATH);
    load_texture("ROAD_LEFT_BOTTOMDASH_NORMAL", LEFT_BOTTOMDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_LEFT_BOTTOMDASH_TOP", LEFT_BOTTOMDASH_TOP_FILE_PATH);
    load_texture("ROAD_LEFT_FULLDASH_NORMAL", LEFT_FULLDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_LEFT_NODASH_BOTTOM", LEFT_NODASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_LEFT_NODASH_NORMAL", LEFT_NODASH_NORMAL_FILE_PATH);
    load_texture("ROAD_LEFT_NODASH_TOP", LEFT_NODASH_TOP_FILE_PATH);
    load_texture("ROAD_LEFT_NOLINE", LEFT_NOLINE_FILE_PATH);
    load_texture("ROAD_LEFT_TOPDASH_BOTTOM", LEFT_TOPDASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_LEFT_TOPDASH_NORMAL", LEFT_TOPDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_BOTTOMDASH_NORMAL", RIGHT_BOTTOMDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_BOTTOMDASH_TOP", RIGHT_BOTTOMDASH_TOP_FILE_PATH);
    load_texture("ROAD_RIGHT_FULLDASH_NORMAL", RIGHT_FULLDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_NODASH_BOTTOM", RIGHT_NODASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_RIGHT_NODASH_NORMAL", RIGHT_NODASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_NODASH_TOP", RIGHT_NODASH_TOP_FILE_PATH);
    load_texture("ROAD_RIGHT_NOLINE", RIGHT_NOLINE_FILE_PATH);
    load_texture("ROAD_RIGHT_TOPDASH_BOTTOM", RIGHT_TOPDASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_RIGHT_TOPDASH_NORMAL", RIGHT_TOPDASH_NORMAL_FILE_PATH);
    load_texture("RIVER", RIVER_FILE_PATH);
    load_texture("TRAFFIC_RED", TRAFFIC_SIGN_RED_FILE_PATH);
    load_texture("TRAFFIC_YELLOW", TRAFFIC_SIGN_YELLOW_FILE_PATH);
    load_texture("TRAFFIC_GREEN", TRAFFIC_SIGN_GREEN_FILE_PATH);
    // people
    load_texture("MARIO_FORWARD", MARIO_FORWARD_FILE_PATH);
    load_texture("MARIO_DOWNWARD", MARIO_DOWNWARD_FILE_PATH);
    load_texture("MARIO_RIGHT", MARIO_RIGHT_FILE_PATH);
    load_texture("MARIO_LEFT", MARIO_LEFT_FILE_PATH);
    // vehicle
    load_texture("CL_0", CL_0);
    load_texture("CL_1", CL_1);
    load_texture("CL_2", CL_2);
    load_texture("CL_3", CL_3);
    load_texture("CL_4", CL_4);
    load_texture("CL_5", CL_5);
    load_texture("CL_6", CL_6);
    load_texture("CL_7", CL_7);
    load_texture("CL_8", CL_8);
    load_texture("CR_0", CR_0);
    load_texture("CR_1", CR_1);
    load_texture("CR_2", CR_2);
    load_texture("CR_3", CR_3);
    load_texture("CR_4", CR_4);
    load_texture("CR_5", CR_5);
    load_texture("CR_6", CR_6);
    load_texture("CR_7", CR_7);
    load_texture("CR_8", CR_8);

    load_texture("CROC_LEFT",CROC_LEFT_FILE_PATH );
    load_texture("CROC_RIGHT",CROC_RIGHT_FILE_PATH );
    load_texture("HIPPO_LEFT",HIPPO_LEFT_FILE_PATH );
    load_texture("HIPPO_RIGHT",HIPPO_RIGHT_FILE_PATH );

    load_texture("LOG", LOG_PATH);
}

