//
//  TrafficLight.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 04/11/2022.
//

#ifndef TrafficLight_hpp
#define TrafficLight_hpp

#include <SFML/Graphics.hpp>
#include "src/Handler.hpp"

class TrafficLight {
    
public:
    
    /* CONSTRUCTORS & DESTRUCTORS */
    
    TrafficLight() = default;
    
    TrafficLight(handler_ptr tools);
    
    ~TrafficLight() {}
    
    /* BEHAVIOUR */
    
    void turn_red();
    
    void turn_yellow();
    
    void turn_green();
    
    void locate_at(float x, float y);
    
    void draw();
    
private:
    
    handler_ptr tools;
    
    sf::Sprite sprite;
    
};

#endif /* TrafficLight_hpp */
