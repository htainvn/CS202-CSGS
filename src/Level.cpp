//
//  Level.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 24/11/2022.
//

#include "Level.hpp"

void Level::dec_path()
{
    --path_left;
}

void Level::dec_road()
{
    --road_left;
}

int Level::spawn_next_lane()
{
    if (!out_of_path())
    {
        dec_path();
        return out_of_path();
    }
    dec_road();
    return (rand() % (100)) % 2 + 2;
}

bool Level::out_of_path()
{
    return (path_left == 0);
}

bool Level::out_of_road()
{
    return (road_left == 0);
}

void Level::goto_next_level()
{
    ++level;
    path_left = rand() % 3 + 1;
    road_left = (level-1) / CAR_PER_LANE + 1;
}

Level::Level(const Level &another) { 
    *this = another;
}

int Level::lev() { 
    return level;
}









