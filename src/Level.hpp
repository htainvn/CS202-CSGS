//
//  Level.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 24/11/2022.
//

#ifndef Level_hpp
#define Level_hpp

#include <stdio.h>
#include <ctime>
#include "src/definition_library.hpp"

class Level {
    
public:
    Level() = default;
    
    Level(int _lev, int _path, int _road) : level(_lev), path_left(_path), road_left(_road) {}
    
    Level(const Level& another);
    
    void dec_path(); //decrease the number of path left
    
    void dec_road(); //decrease the number of road left
    
    bool out_of_path();
    
    bool out_of_road();
    
    int spawn_next_lane(); //tell us what the next lane would be
    
    void goto_next_level();
    
    int lev();

    int road_remain(); // return number of road remain in level
    
    ~Level() {}
    
private:
    
    int level = 0;
    
    int path_left = 0;
    
    int road_left = 0;
};

#endif /* Level_hpp */
