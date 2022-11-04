//
//  TrafficLight.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 04/11/2022.
//

#include "TrafficLight.hpp"

TrafficLight::TrafficLight(ResourceManager& resource_manager) {
    sprite.setTexture(resource_manager.get_texture("TRAFFIC_RED"));
}
