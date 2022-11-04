//
//  TrafficLight.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 04/11/2022.
//

#ifndef TrafficLight_hpp
#define TrafficLight_hpp

#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class TrafficLight {
private:
    sf::Sprite sprite;
    int status = 0;
public:
    TrafficLight(ResourceManager& resource_manager);
    void turn_red();
    void turn_yellow();
    void turn_green();
};

#endif /* TrafficLight_hpp */
