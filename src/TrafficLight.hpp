//
//  TrafficLight.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 04/11/2022.
//

#ifndef TrafficLight_hpp
#define TrafficLight_hpp

#include <SFML/Graphics.hpp>
#include "src/ResourceManager.hpp"

class TrafficLight {
private:
    sf::Sprite sprite;
    int status = 0;
public:
    TrafficLight() = default;
    TrafficLight(sf::Texture& texture);
    void turn_red(sf::Texture& texture);
    void turn_yellow(sf::Texture& texture);
    void turn_green(sf::Texture& texture);
    void allocate_position(float oy);
    sf::Sprite out_scr();
};

#endif /* TrafficLight_hpp */
