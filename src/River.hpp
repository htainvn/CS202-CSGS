//
//  River.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef River_hpp
#define River_hpp

#include <stdio.h>
#include "Lane.hpp"

class River : public Lane {
private:
    
public:
    River(sf::Texture& texture);
    int get_lane_type();
    void allocate_lane_position(float x, float y);
    ~River() {}
};

#endif /* River_hpp */
