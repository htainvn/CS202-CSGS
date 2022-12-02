//
//  TrafficLight.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 04/11/2022.
//

#include "src/TrafficLight.hpp"


void TrafficLight::turn_red() { 
    sprite.setTexture(tools->theme_controller.get("TRAFFIC_RED"));
}

void TrafficLight::turn_yellow() { 
    sprite.setTexture(tools->theme_controller.get("TRAFFIC_YELLOW"));
}

void TrafficLight::turn_green() { 
    sprite.setTexture(tools->theme_controller.get("TRAFFIC_GREEN"));
}

void TrafficLight::locate_at(float x, float y) { 
    sprite.setPosition(sf::Vector2f(x, y));
}

void TrafficLight::draw() { 
    tools->window.draw(sprite);
}

TrafficLight::TrafficLight(Handler *_tools) : tools(_tools) {
    sprite.setTexture(tools->theme_controller.get("TRAFFIC_RED"));
}


