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

/*
class River : public Lane {
private:
    std::vector<Log*> logs;
    std::vector<Animal*> animals;
public:
    River(sf::Texture& texture);
    int get_lane_type();
    void allocate_lane_position(ResourceManager& resource_manager, float x, float y);
    void adjust_objects();
    std::vector<sf::Sprite> all_relative_object();
    
    //undone
    void add_log(Log*& log) {}
    void add_animal(Animal*& animal) {}
    void stop_traffic() {}
    void spawn_animal(ResourceManager& resourmanager, float x, int num_of_animals);
    
    
    ~River();
};
*/

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
