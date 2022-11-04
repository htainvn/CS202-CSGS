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

#include "src/ResourceManager.hpp"
#include "src/Lane.hpp"
#include "src/Pathway.hpp"
#include "src/River.hpp"
#include "src/Road.hpp"

class LaneGenerator {
    
private:
    std::vector<Lane> lanes;
    
    std::vector<Lane> prediction;
    
public:
    
    void add_lane(ResourceManager& resource_manager, float oy, int type_of_lane);
    
    void delete_bottom_lane();
    
    void moving_lanes(float moving_speed, bool& isShifting, ResourceManager& resource_manager);
    
    int counting_lanes();
    
    Lane operator[](const int index);
    
    int get_prediction_type();
    
    ~LaneGenerator() {}
};

#endif /* Background_hpp */
