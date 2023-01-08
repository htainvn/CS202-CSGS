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
#include "src/Pathway.hpp"
#include "src/River.hpp"
#include "src/Road.hpp"

class LaneFactory {
    
public:
    
    LaneFactory() = default;
    
    LaneFactory(handler_ptr _tools) : tools(_tools)
    {
        level = new Level(3, 0, 1);
    }
    
    LaneFactory(const LaneFactory& other) : tools(other.tools){
        level = new Level(*other.level);
        lanes.resize(other.lanes.size());
        for (int i=0; i<lanes.size(); i++){
            int t = other.lanes[i]->type();
            switch(t){
                case PATHWAY_TYPE:{
                    lanes[i] = new Pathway(this->tools, other.lanes[i]->position(), other.lanes[i]->Level_());
                    *lanes[i] = *other.lanes[i];
                    break;
                }
                case PATHWAYLIGHT_TYPE:
                {
                    lanes[i] = new PathwayLight(this->tools, other.lanes[i]->position(), other.lanes[i]->Level_());
                    *lanes[i] = *other.lanes[i];
                    break;
                }
                case RIVER_TYPE:{
                    River* tov = dynamic_cast<River*>(other.lanes[i]);
                    lanes[i] = new River(tov);
                    break;
                }
                case ROAD_TYPE:{
                    Road* tiv = dynamic_cast<Road*>(other.lanes[i]);
                    lanes[i] = new Road(tiv);
                    //lanes[i] = new Road(dynamic_cast<Road*>(other.lanes[i]));
                    break;
                }
            }
        }
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
        for (int i = 0; i < lanes.size(); i++) {
            if (lanes[0] != nullptr) {
                delete lanes[0];
                lanes[0] = nullptr;
            }
            lanes.erase(lanes.begin());
        }
    }
    
private:
    
    handler_ptr tools = nullptr;
    
    level_ptr level = nullptr;
    
    std::vector<Lane*> lanes;
};

#endif /* Background_hpp */
