//
//  Pathway.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Pathway_hpp
#define Pathway_hpp

#include <stdio.h>
#include "src/Lane.hpp"
#include "src/Handler.hpp"
#include "src/TrafficLight.hpp"

class Pathway : public Lane {
public:
    
/* CONSTRUCTORS & DESTRUCTORS */
    
    Pathway(handler_ptr _tools);
    
    Pathway(handler_ptr _tools, float x, float y);
    
    Pathway(handler_ptr _tools, Position pos);

    ~Pathway() {}
    
/* END HERE */
    
/* OVERRIDEN FUNCTIONS */
    
    void draw();
    
    int type() { return PATHWAY_TYPE; }
    
/* END HERE */
};

class PathwayLight : public Pathway {
    
public:
    
/* CONSTRUCTORS & DESTRUCTORS */
    
    PathwayLight(handler_ptr _tools);
    
    PathwayLight(handler_ptr _tools, float x, float y);
    
    PathwayLight(handler_ptr _tools, Position pos);

    ~PathwayLight() {}
    
/* END HERE */
    
/* OVERRIDEN FUNCTIONS */
    
    void draw();
    
    void adjust_objects();
    
    int type() { return PATHWAYLIGHT_TYPE; }
    
    void stop();
    
    void slowdown();
    
    void run();
    
/* END HERE */
    
    
private:
    TrafficLight light;
    
private:
    void update_traffic(int sign); //sign = (0: red, 1: yellow, 2: green)
    
};

#endif /* Pathway_hpp */
