//
//  Handler.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Handler_h
#define Handler_h

#include <SFML/Graphics.hpp>
#include "StateManager.hpp"
#include "ResourceManager.hpp"
#include "LaneGenerator.hpp"

#include "Lane.hpp"

class Handler {
public:
    StateManager state_manager;
    ResourceManager resource_manager;
    sf::RenderWindow window;
    
    Handler() {
        this->state_manager = StateManager();
    }
    
    void display_lane(LaneGenerator& lane_gen) {
        int n = lane_gen.counting_lanes();
        for (int i = 0; i < n; i++) {
            lane_gen[i].sprite.setPosition(sf::Vector2f(window.getSize().x, 0));
            window.draw(lane_gen[i].sprite);
        }
    }
    
};

#endif /* Handler_h */
