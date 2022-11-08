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
#include "src/TrafficLight.hpp"

class Pathway : public Lane {
public:
    Pathway() {}
    int get_lane_type();
    Pathway(sf::Texture& texture);
    void allocate_lane_position(float x, float y);
    void adjust_object() {}
    std::vector<sf::Sprite> all_relative_object() {
        std::vector<sf::Sprite> res;
        return res;
    }
    ~Pathway() {}
};

class PathwayLight : public Pathway {
public:
    TrafficLight light;
    PathwayLight(sf::Texture& texture_path, sf::Texture& texture_light);
    void allocate_lane_position(float x, float y);
    void adjust_objects();
    std::vector<sf::Sprite> all_relative_object();
    int get_lane_type();
    void update_traffic(ResourceManager& resource_manager, int status, sf::Clock& clock);
    ~PathwayLight() {}
};

#endif /* Pathway_hpp */
