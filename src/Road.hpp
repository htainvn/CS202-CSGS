//
//  Road.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Road_hpp
#define Road_hpp

#include <stdio.h>
#include "src/Lane.hpp"

#include "src/Vehicle.hpp"

class Road : public Lane {
    
public:
    
/* CONSTRUCTORS & DESTRUCTORS */
    
    Road(handler_ptr _tools, Level level);
    
    Road(handler_ptr _tools, int _position, int _dir, int _bottom, int _top, Level level, Position pos = Position());
    
    Road(handler_ptr _tools, int another_dir, int& changed_type, Level level, Position pos = Position());
    
    ~Road() {}
    
/* END HERE */
    
/* BEHAVIOUR */
    
    void change_status(int _position = -1, int _dir = -1, int _bottom = -1, int _top = -1);
    
    void reset_texture();
    
    void spawn();
    
    void stop(); //undone
    
    void draw();
    
    void adjust_objects();
    
    int type() { return ROAD_TYPE; }
    
    int direction() { return dir; }
    
    
/* END HERE */
    
private:
    
    int position = 0; //0 is bottom, 1 is normal, 2 is top
    
    int dir = 0; //0 is left, 1 is right
    
    int bottom_type = 0; //0 is nothing, 1 is dash, 2 is line
    
    int top_type = 0; //0 is nothing, 1 is dash, 2 is line
    
    std::vector<Vehicle*> vehicles;

    int max_car = 1;
    
private:
    
    std::string get_texture_code();

    void set_maxcar();
    
};

#endif /* Road_hpp */
