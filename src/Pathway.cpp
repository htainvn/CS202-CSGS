//
//  Pathway.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Pathway.hpp"

Pathway::Pathway(sf::Texture& texture) {
    this->sprite.setTexture(texture);
}

void Pathway::allocate_lane_position(float x, float y) {
    this->sprite.setPosition(sf::Vector2f(x, y));
}

int Pathway::get_lane_type() {
    return PATHWAY_TYPE;
}
