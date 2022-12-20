//
//  Background.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Background_hpp
#define Background_hpp

#include <stdio.h>

#include <vector>

#include "src/Handler.hpp"
#include "src/Lane.hpp"
#include "src/Pathway.hpp"
#include "src/River.hpp"
#include "src/Level.hpp"
#include "src/Road.hpp"

class LaneFactory {
    
public:
    
    LaneFactory() = default;
    
    LaneFactory(handler_ptr _tools) : tools(_tools)
    {
        level = new Level(3, 0, 1);
    }
    
    LaneFactory(handler_ptr _tools, level_ptr _level) : tools(_tools), level(_level) {};
    
    lane_ptr create_lane(int type, Position pos = Position(), Level lev = Level());
    
    void pop_bottom_lane();
    
    void extracted();
    
    void loading(std::ifstream& fin, People*& mariof);
    
    Lane*& at(int const index);
    
    void refactor(float& real_level);
    
    bool detect_outscr();
    
    void add_lane(int type, Position pos = Position(), Level lev = Level());
    
    void next_current(People*& mario);
    
    void horizontal_movement(People *&mario, int type = 0);
    
    void prev_current(People*& mario);

    void save(std::ofstream& fout);
    
    int current();
    
    void stop(); //stop traffic
    
    void slowdown(); //objects run slowly
    
    void run(); //normal
        
    ~LaneFactory()
    {
        if (level)
        {
            delete level;
            
            level = nullptr;
        }
    }
    
private:
    
    handler_ptr tools = nullptr;
    
    level_ptr level = nullptr;
    
    std::vector<Lane*> lanes;
};

#endif /* Background_hpp */
