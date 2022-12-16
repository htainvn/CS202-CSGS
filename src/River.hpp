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
    
    River(handler_ptr _tools, Level level, Position pos = Position(), float last_speed = -1);
    
    ~River();
    
    /* END HERE */
    
    /* BEHAVIOUR */
    
    void stop();

    void slowdown();

    void run();
    
    void spawn();
    
    void adjust_objects();
    
    int type() { return RIVER_TYPE; }
    
    void draw();
    
    bool check_lost();
    
    void set_current(People*& mario, int _type = 0);
    
    void unset();
    
    void loading(std::ifstream& fin);

    void save(std::ofstream& fout);
    
    float get_speed() {return speed;}
    
    /* END HERE */
    
private:

    std::vector<floatObject*> float_objs;

    int max_log;

    bool dir;

    float speed;

    int traffic_light; //0:green 1:red 2: yellow
        
    std::string river_sound_hash_name = "RIVER_SOUND";
    
    sf::Sound river_sound;
    
private:

    int get_maxlog();
    
    int get_currentlog();
    
    int get_nextobj(int current_log_index);
    
    int get_prevobj(int current_log_index);
};

#endif /* River_hpp */
