//
//  Position.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 24/11/2022.
//

#ifndef Position_hpp
#define Position_hpp

#include <stdio.h>

#include "src/definition_library.hpp"

class Position {
private:
    float x = -101;
    float y = -101;
public:
    Position() = default;
    
    Position(float _x, float _y) : x(_x), y(_y) {}
    
    float get_x() {
        return x;
    }
    
    float get_y() {
        return y;
    }
    
    bool out_of_screen() {
        return ((x < 0) | (x > SCREEN_WIDTH) | (y < 0) | (y > SCREEN_HEIGHT));
    }
};


#endif /* Position_hpp */
