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
        this->texture_warehouse.push_back(make_pair(hash_name, texture));
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

void ResourceManager::load_music(std::string current_theme, sf::Music& theme_sound) {
    std::string filepath;
    
    if (current_theme == "lava")
        filepath = LAVA_THEME_SOUND_FILE_PATH;
    else
        filepath = NORMAL_THEME_SOUND_FILE_PATH;

    if (!theme_sound.openFromFile(filepath)) {
        std::cout << "error at: " << filepath << "\n";
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

void ResourceManager::load(std::string theme) {
    
    storage.clear();
    
    for (int i = 0; i < texture_warehouse.size(); i++) {
        if (texture_warehouse[i].first.find(theme) != std::string::npos) {
            std::string temp = texture_warehouse[i].first;
            temp.erase(texture_warehouse[i].first.find(theme)-1, theme.length()+1); //for character '_'
            storage.push_back(make_pair(temp, texture_warehouse[i].second));
        }
    }
}

void ResourceManager::loadTextureData(const std::string &theme) {
    load_texture("LOST_SCREEN_" + theme, WORKING_DIR + "/src_design/background/" + theme + LOST_BACKGROUND);
    load_texture("HEADSTONE_" + theme, WORKING_DIR + "/src_design/background/" + theme + HEADSTONE);
    load_texture("BLACKBOARD_" + theme, WORKING_DIR + "/src_design/background/" + theme + BlackBoard);
    
    load_texture("PAVEMENT_" + theme, WORKING_DIR + "/src_design/environment/" + theme + PAVEMENT_IMAGE_FILE_PATH);
    load_texture("ROAD_LEFT_BOTTOMDASH_NORMAL_" + theme, WORKING_DIR + "/src_design/environment/" + theme + LEFT_BOTTOMDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_LEFT_BOTTOMDASH_TOP_" + theme, WORKING_DIR + "/src_design/environment/" + theme + LEFT_BOTTOMDASH_TOP_FILE_PATH);
    load_texture("ROAD_LEFT_FULLDASH_NORMAL_" + theme, WORKING_DIR + "/src_design/environment/" + theme + LEFT_FULLDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_LEFT_NODASH_BOTTOM_" + theme, WORKING_DIR + "/src_design/environment/" + theme + LEFT_NODASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_LEFT_NODASH_NORMAL_" + theme, WORKING_DIR + "/src_design/environment/" + theme + LEFT_NODASH_NORMAL_FILE_PATH);
    load_texture("ROAD_LEFT_NODASH_TOP_" + theme, WORKING_DIR + "/src_design/environment/" + theme + LEFT_NODASH_TOP_FILE_PATH);
    load_texture("ROAD_LEFT_NOLINE_" + theme, WORKING_DIR + "/src_design/environment/" + theme + LEFT_NOLINE_FILE_PATH);
    load_texture("ROAD_LEFT_TOPDASH_BOTTOM_" + theme, WORKING_DIR + "/src_design/environment/" + theme + LEFT_TOPDASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_LEFT_TOPDASH_NORMAL_" + theme, WORKING_DIR + "/src_design/environment/" + theme + LEFT_TOPDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_BOTTOMDASH_NORMAL_" + theme, WORKING_DIR + "/src_design/environment/" + theme + RIGHT_BOTTOMDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_BOTTOMDASH_TOP_" + theme, WORKING_DIR + "/src_design/environment/" + theme + RIGHT_BOTTOMDASH_TOP_FILE_PATH);
    load_texture("ROAD_RIGHT_FULLDASH_NORMAL_" + theme, WORKING_DIR + "/src_design/environment/" + theme + RIGHT_FULLDASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_NODASH_BOTTOM_" + theme, WORKING_DIR + "/src_design/environment/" + theme + RIGHT_NODASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_RIGHT_NODASH_NORMAL_" + theme, WORKING_DIR + "/src_design/environment/" + theme + RIGHT_NODASH_NORMAL_FILE_PATH);
    load_texture("ROAD_RIGHT_NODASH_TOP_" + theme, WORKING_DIR + "/src_design/environment/" + theme + RIGHT_NODASH_TOP_FILE_PATH);
    load_texture("ROAD_RIGHT_NOLINE_" + theme, WORKING_DIR + "/src_design/environment/" + theme + RIGHT_NOLINE_FILE_PATH);
    load_texture("ROAD_RIGHT_TOPDASH_BOTTOM_" + theme, WORKING_DIR + "/src_design/environment/" + theme + RIGHT_TOPDASH_BOTTOM_FILE_PATH);
    load_texture("ROAD_RIGHT_TOPDASH_NORMAL_" + theme, WORKING_DIR + "/src_design/environment/" + theme + RIGHT_TOPDASH_NORMAL_FILE_PATH);
    load_texture("RIVER_" + theme, WORKING_DIR + "/src_design/environment/" + theme + RIVER_FILE_PATH);
    load_texture("TRAFFIC_RED_" + theme, WORKING_DIR + "/src_design/environment/" + theme + TRAFFIC_SIGN_RED_FILE_PATH);
    load_texture("TRAFFIC_YELLOW_" + theme, WORKING_DIR + "/src_design/environment/" + theme + TRAFFIC_SIGN_YELLOW_FILE_PATH);
    load_texture("TRAFFIC_GREEN_" + theme, WORKING_DIR + "/src_design/environment/" + theme + TRAFFIC_SIGN_GREEN_FILE_PATH);
    
    // people
    load_texture("MARIO_FORWARD_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_FORWARD_FILE_PATH);
    load_texture("MARIO_DOWNWARD_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_DOWNWARD_FILE_PATH);
    load_texture("MARIO_RIGHT_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_RIGHT_FILE_PATH);
    load_texture("MARIO_LEFT_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_LEFT_FILE_PATH);
    load_texture("MARIO_FORWARDGO_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_MOVEFORWARD_FILE_PATH);
    load_texture("MARIO_DOWNWARDGO_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_MOVEDOWNWARD_FILE_PATH);
    load_texture("MARIO_RIGHTGO_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_MOVERIGHT_FILE_PATH);
    load_texture("MARIO_RIGHTRUN_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_RUNRIGHT_FILE_PATH);
    load_texture("MARIO_LEFTRUN_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_RUNLEFT_FILE_PATH);
    load_texture("MARIO_FORWARDRUN_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_RUNFORWARD_FILE_PATH);
    load_texture("MARIO_DOWNRUN_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_RUNDOWN_FILE_PATH);
    load_texture("MARIO_LEFTGO_" + theme, WORKING_DIR + "/src_design/people/" + theme + MARIO_MOVELEFT_FILE_PATH);
    
    
    // vehicle
    load_texture("CL_0_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CL_0);
    load_texture("CL_1_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CL_1);
    load_texture("CL_2_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CL_2);
    load_texture("CL_3_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CL_3);
    load_texture("CL_4_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CL_4);
    load_texture("CL_5_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CL_5);
    load_texture("CL_6_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CL_6);
    load_texture("CL_7_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CL_7);
    load_texture("CL_8_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CL_8);
    load_texture("CR_0_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CR_0);
    load_texture("CR_1_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CR_1);
    load_texture("CR_2_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CR_2);
    load_texture("CR_3_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CR_3);
    load_texture("CR_4_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CR_4);
    load_texture("CR_5_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CR_5);
    load_texture("CR_6_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CR_6);
    load_texture("CR_7_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CR_7);
    load_texture("CR_8_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + CR_8);
    
    load_texture("CROC_LEFT_" + theme, WORKING_DIR + "/src_design/animal/" + theme + CROC_LEFT_FILE_PATH );
    load_texture("CROC_RIGHT_" + theme, WORKING_DIR + "/src_design/animal/" + theme + CROC_RIGHT_FILE_PATH );
    load_texture("HIPPO_LEFT_" + theme, WORKING_DIR + "/src_design/animal/" + theme + HIPPO_LEFT_FILE_PATH );
    load_texture("HIPPO_RIGHT_" + theme, WORKING_DIR + "/src_design/animal/" + theme + HIPPO_RIGHT_FILE_PATH );
    
    load_texture("LOG_" + theme, WORKING_DIR + "/src_design/vehicle/" + theme + LOG_PATH);
}

void ResourceManager::init()
{
    
    std::string theme = "modern";
    loadTextureData(theme);
    
    theme = "neon";
    loadTextureData(theme);
    
    theme = "8bit";
    loadTextureData(theme);
    
    theme = "lava";
    loadTextureData(theme);
    
    //sound
    load_sound_buffer("CROC_SOUND", WORKING_DIR + "/src_design/sound/" + CROC_SOUND_FILE_PATH);
    
    load_sound_buffer("ZOMBIE_SOUND", WORKING_DIR + "/src_design/sound/" + ZOMBIE_SOUND_FILE_PATH);
    
    load_sound_buffer("CAR_SOUND", WORKING_DIR + "/src_design/sound/" + CAR_SOUND_FILE_PATH);
    
    load_sound_buffer("STONE_SOUND", WORKING_DIR + "/src_design/sound/" + STONE_SOUND_FILE_PATH);

    load_sound_buffer("RIVER_SOUND", WORKING_DIR + "/src_design/sound/" + RIVER_SOUND_FILE_PATH);
}
