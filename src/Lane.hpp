//
//  Lane.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Lane_hpp
#define Lane_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "src/definition_library.hpp"

class Lane {
public:
    sf::Sprite sprite;
    int get_lane_type() {}
    void allocate_lane_position(float x, float y) {}
    ~Lane() {}
};

#endif /* Lane_hpp */
