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

void ResourceManager::load_sound_buffer(std::string hash_name, std::string path) {
    sf::SoundBuffer buffer;
    if (buffer.loadFromFile(path)) {
        this->sound_storage.push_back(make_pair(hash_name, buffer));
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

sf::SoundBuffer& ResourceManager::get_sound_buffer(std::string hash_name) {
    for (int i = 0; i < sound_storage.size(); ++i) {
        if (sound_storage[i].first == hash_name) {
            return sound_storage[i].second;
        }
    }
    return sound_storage[0].second;
}

void ResourceManager::init(std::string theme)
{
    
    storage.clear();
    
    load_texture("PAVEMENT", WORKING_DIR + "/src_design/environment/" + theme + PAVEMENT_IMAGE_FILE_PATH);
    load_texture("ROAD_LEFT_BOTTOMDASH_NORMAL", WORKING_DIR + "/src_design/environment/" + theme + LEFT_BOTTOMDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_LEFT_BOTTOMDASH_TOP", WORKING_DIR + "/src_design/environment/" + theme + LEFT_BOTTOMDASH_TOP_FILE_PATH);
    load_texture("ROAD_LEFT_FULLDASH_NORMAL", WORKING_DIR + "/src_design/environment/" + theme + LEFT_FULLDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_LEFT_NODASH_BOTTOM", WORKING_DIR + "/src_design/environment/" + theme + LEFT_NODASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_LEFT_NODASH_NORMAL", WORKING_DIR + "/src_design/environment/" + theme + LEFT_NODASH_NORMAL_FILE_PATH);
    load_texture("ROAD_LEFT_NODASH_TOP", WORKING_DIR + "/src_design/environment/" + theme + LEFT_NODASH_TOP_FILE_PATH);
    load_texture("ROAD_LEFT_NOLINE", WORKING_DIR + "/src_design/environment/" + theme + LEFT_NOLINE_FILE_PATH);
    load_texture("ROAD_LEFT_TOPDASH_BOTTOM", WORKING_DIR + "/src_design/environment/" + theme + LEFT_TOPDASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_LEFT_TOPDASH_NORMAL", WORKING_DIR + "/src_design/environment/" + theme + LEFT_TOPDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_BOTTOMDASH_NORMAL", WORKING_DIR + "/src_design/environment/" + theme + RIGHT_BOTTOMDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_BOTTOMDASH_TOP", WORKING_DIR + "/src_design/environment/" + theme + RIGHT_BOTTOMDASH_TOP_FILE_PATH);
    load_texture("ROAD_RIGHT_FULLDASH_NORMAL", WORKING_DIR + "/src_design/environment/" + theme + RIGHT_FULLDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_NODASH_BOTTOM", WORKING_DIR + "/src_design/environment/" + theme + RIGHT_NODASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_RIGHT_NODASH_NORMAL", WORKING_DIR + "/src_design/environment/" + theme + RIGHT_NODASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_NODASH_TOP", WORKING_DIR + "/src_design/environment/" + theme + RIGHT_NODASH_TOP_FILE_PATH);
    load_texture("ROAD_RIGHT_NOLINE", WORKING_DIR + "/src_design/environment/" + theme + RIGHT_NOLINE_FILE_PATH);
    load_texture("ROAD_RIGHT_TOPDASH_BOTTOM", WORKING_DIR + "/src_design/environment/" + theme + RIGHT_TOPDASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_RIGHT_TOPDASH_NORMAL", WORKING_DIR + "/src_design/environment/" + theme + RIGHT_TOPDASH_NORMAL_FILE_PATH);
    load_texture("RIVER", WORKING_DIR + "/src_design/environment/" + theme + RIVER_FILE_PATH);
    load_texture("TRAFFIC_RED", WORKING_DIR + "/src_design/environment/" + theme + TRAFFIC_SIGN_RED_FILE_PATH);
    load_texture("TRAFFIC_YELLOW", WORKING_DIR + "/src_design/environment/" + theme + TRAFFIC_SIGN_YELLOW_FILE_PATH);
    load_texture("TRAFFIC_GREEN", WORKING_DIR + "/src_design/environment/" + theme + TRAFFIC_SIGN_GREEN_FILE_PATH);
    
    // people
    load_texture("MARIO_FORWARD", WORKING_DIR + "/src_design/people/" + theme + MARIO_FORWARD_FILE_PATH);
    load_texture("MARIO_DOWNWARD", WORKING_DIR + "/src_design/people/" + theme + MARIO_DOWNWARD_FILE_PATH);
    load_texture("MARIO_RIGHT", WORKING_DIR + "/src_design/people/" + theme + MARIO_RIGHT_FILE_PATH);
    load_texture("MARIO_LEFT", WORKING_DIR + "/src_design/people/" + theme + MARIO_LEFT_FILE_PATH);
    load_texture("MARIO_FORWARDGO", WORKING_DIR + "/src_design/people/" + theme + MARIO_MOVEFORWARD_FILE_PATH);
    load_texture("MARIO_DOWNWARDGO", WORKING_DIR + "/src_design/people/" + theme + MARIO_MOVEDOWNWARD_FILE_PATH);
    load_texture("MARIO_RIGHTGO", WORKING_DIR + "/src_design/people/" + theme + MARIO_MOVERIGHT_FILE_PATH);
    load_texture("MARIO_RIGHTRUN", WORKING_DIR + "/src_design/people/" + theme + MARIO_RUNRIGHT_FILE_PATH);
    load_texture("MARIO_LEFTRUN", WORKING_DIR + "/src_design/people/" + theme + MARIO_RUNLEFT_FILE_PATH);
    load_texture("MARIO_FORWARDRUN", WORKING_DIR + "/src_design/people/" + theme + MARIO_RUNFORWARD_FILE_PATH);
    load_texture("MARIO_DOWNRUN", WORKING_DIR + "/src_design/people/" + theme + MARIO_RUNDOWN_FILE_PATH);
    load_texture("MARIO_LEFTGO", WORKING_DIR + "/src_design/people/" + theme + MARIO_MOVELEFT_FILE_PATH);
    
    
    // vehicle
    load_texture("CL_0", WORKING_DIR + "/src_design/vehicle/" + theme + CL_0);
    load_texture("CL_1", WORKING_DIR + "/src_design/vehicle/" + theme + CL_1);
    load_texture("CL_2", WORKING_DIR + "/src_design/vehicle/" + theme + CL_2);
    load_texture("CL_3", WORKING_DIR + "/src_design/vehicle/" + theme + CL_3);
    load_texture("CL_4", WORKING_DIR + "/src_design/vehicle/" + theme + CL_4);
    load_texture("CL_5", WORKING_DIR + "/src_design/vehicle/" + theme + CL_5);
    load_texture("CL_6", WORKING_DIR + "/src_design/vehicle/" + theme + CL_6);
    load_texture("CL_7", WORKING_DIR + "/src_design/vehicle/" + theme + CL_7);
    load_texture("CL_8", WORKING_DIR + "/src_design/vehicle/" + theme + CL_8);
    load_texture("CR_0", WORKING_DIR + "/src_design/vehicle/" + theme + CR_0);
    load_texture("CR_1", WORKING_DIR + "/src_design/vehicle/" + theme + CR_1);
    load_texture("CR_2", WORKING_DIR + "/src_design/vehicle/" + theme + CR_2);
    load_texture("CR_3", WORKING_DIR + "/src_design/vehicle/" + theme + CR_3);
    load_texture("CR_4", WORKING_DIR + "/src_design/vehicle/" + theme + CR_4);
    load_texture("CR_5", WORKING_DIR + "/src_design/vehicle/" + theme + CR_5);
    load_texture("CR_6", WORKING_DIR + "/src_design/vehicle/" + theme + CR_6);
    load_texture("CR_7", WORKING_DIR + "/src_design/vehicle/" + theme + CR_7);
    load_texture("CR_8", WORKING_DIR + "/src_design/vehicle/" + theme + CR_8);

    load_texture("CROC_LEFT", WORKING_DIR + "/src_design/animal/" + theme + CROC_LEFT_FILE_PATH );
    load_texture("CROC_RIGHT", WORKING_DIR + "/src_design/animal/" + theme + CROC_RIGHT_FILE_PATH );
    load_texture("HIPPO_LEFT", WORKING_DIR + "/src_design/animal/" + theme + HIPPO_LEFT_FILE_PATH );
    load_texture("HIPPO_RIGHT", WORKING_DIR + "/src_design/animal/" + theme + HIPPO_RIGHT_FILE_PATH );

    load_sound_buffer("CROC_SOUND", WORKING_DIR + "/src_design/animal/" + CROC_SOUND_FILE_PATH);
    load_sound_buffer("ZOMBIE_SOUND", WORKING_DIR + "/src_design/animal/" + ZOMBIE_SOUND_FILE_PATH);
    load_sound_buffer("RIVER_SOUND",WORKING_DIR + "/src_design/environment/" + RIVER_SOUND_FILE_PATH);

    load_texture("LOG", WORKING_DIR + "/src_design/vehicle/" + theme + LOG_PATH);
}

