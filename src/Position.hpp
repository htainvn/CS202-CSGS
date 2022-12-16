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
    
    bool inRect(Position& another, Position size)
    {
        int xPeople = (int) x;
        int yPeople = (int) y;
        int xObject = (int) another.x;
        int yObject = (int) another.y;
        
        if (xPeople > xObject + dsize) return false;
        if (xPeople < xObject - size.x) return false;
        if (yPeople > yObject + dsize) return false;
        if (yPeople < yObject) return false;
        return true;
    }
};


#endif /* Position_hpp */
