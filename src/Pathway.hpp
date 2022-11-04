//
//  Pathway.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Pathway_hpp
#define Pathway_hpp

#include <stdio.h>
#include "Lane.hpp"


class Pathway : public Lane {
private:
    
public:
    int get_lane_type();
    Pathway(sf::Texture& texture);
    void allocate_lane_position(float x, float y);
    ~Pathway() {}
};

#endif /* Pathway_hpp */
