//
//  Handler.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Handler_h
#define Handler_h

#include <SFML/Graphics.hpp>
#include "src/StateManager.hpp"
#include "src/ResourceManager.hpp"

class Handler {
public:
    
    StateManager state_manager;
    
    ResourceManager resource_manager;
    
    sf::RenderWindow window;
    
    Handler() {
        this->state_manager = StateManager();
    }
    
    /*void display_lane(LaneGenerator& lane_gen) {
        int n = lane_gen.counting_lanes();
        for (int i = 0; i < n; i++) {
            window.draw(lane_gen[i]->sprite);
        }
        for (int i = n-1; i >= 0; i--) {
            auto cus = lane_gen[i]->all_relative_object();
            for (int j = 0; j < cus.size(); j++) {
                window.draw(cus[j]);
                //if (lane_gen[i]->get_lane_type() == 2) std::cout << cus[j].getPosition().x << " " << cus[j].getPosition().y << '\n';
            }
        }
    }*/
    
};

#endif /* Handler_h */
