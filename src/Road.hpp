//
//  Road.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Road_hpp
#define Road_hpp

#include <stdio.h>
#include "Lane.hpp"

class Road : public Lane {
private:
    
public:
    Road(sf::Texture& texture);
    int get_lane_type();
    void allocate_lane_position(float x, float y);
    ~Road() {}
};

#endif /* Road_hpp */
