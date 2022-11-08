//
//  River.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/River.hpp"

int River::get_lane_type() {
    return RIVER_TYPE;
}

River::River(sf::Texture& texture) {
    sprite.setTexture(texture);
}

void River::allocate_lane_position(float x, float y) {
    sprite.setPosition(sf::Vector2f(x,y));
}

void River::adjust_objects() {}

std::vector<sf::Sprite> River::all_relative_object() {
    std::vector<sf::Sprite> res;
    return res;
}
