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
#include "src/Log.hpp"
#include "src/Animal.hpp"

class River : public Lane {
    
public:
    
    /* CONSTRUCTORS & DESTRUCTORS */
    
    River(handler_ptr _tools, Level level, Position pos = Position());
    
    ~River();
    
    /* END HERE */
    
    /* BEHAVIOUR */
    
    void stop();
    
    void spawn();
    
    void adjust_objects();
    
    int type() { return RIVER_TYPE; }
    
    void draw();
    
    bool check_lost();
    
    void set_current(People*& mario);
    
    void unset();
    
    /* END HERE */
    
private:

    std::vector<floatObject*> float_objs;

    int max_log;

    bool dir;

    float speed;
    

private:

    int get_maxlog();

};

#endif /* River_hpp */
