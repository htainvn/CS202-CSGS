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
    
    bool out_of_screen(bool type) {
        if (!type) return ((x < -100) | (x > SCREEN_WIDTH));
       return ((y < -100) | (y > SCREEN_HEIGHT));
    }
    
    bool inRect(Position& another)
    {
        if (x > another.get_x() + dsize) return false;
        if (x < another.get_x()) return false;
        if (y > another.get_y() + dsize) return false;
        if (y < another.get_y()) return false;
        return true;
    }
};


#endif /* Position_hpp */
