//
//  River.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef River_hpp
#define River_hpp

#include <stdio.h>
#include "src/Lane.hpp"
#include "src/Vehicle.hpp"
#include "src/Animal.hpp"

class River : public Lane {
    
public:
    
    /* CONSTRUCTORS & DESTRUCTORS */
    
    River(handler_ptr _tools, Position pos = Position());
    
    ~River() {}
    
    /* END HERE */
    
    /* BEHAVIOUR */
    
    void stop();
    
    void spawn();
    
    void adjust_objects();
    
    int type() { return RIVER_TYPE; }
    
    
    /* END HERE */
    
private:
    
    std::vector<Log*> logs;
    
    std::vector<Animal*> animals;
    
};

#endif /* River_hpp */
