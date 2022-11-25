//
//  TrafficLight.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 04/11/2022.
//

#include "src/TrafficLight.hpp"

/*

TrafficLight::TrafficLight(sf::Texture& texture) {
    sprite.setTexture(texture);
}

void TrafficLight::turn_red(sf::Texture& texture) {
    sprite.setTexture(texture);
}

void TrafficLight::turn_yellow(sf::Texture& texture) {
    sprite.setTexture(texture);
}

void TrafficLight::turn_green(sf::Texture& texture) {
    sprite.setTexture(texture);
}

void TrafficLight::allocate_position(float oy) {
    sprite.setPosition(sf::Vector2f(800, oy-70));
}

sf::Sprite TrafficLight::out_scr() {
    return this->sprite;
}

*/


void TrafficLight::turn_red() { 
    sprite.setTexture(tools->resource_manager.get_texture("TRAFFIC_RED"));
}

void TrafficLight::turn_yellow() { 
    sprite.setTexture(tools->resource_manager.get_texture("TRAFFIC_YELLOW"));
}

void TrafficLight::turn_green() { 
    sprite.setTexture(tools->resource_manager.get_texture("TRAFFIC_GREEN"));
}

void TrafficLight::locate_at(float x, float y) { 
    sprite.setPosition(sf::Vector2f(x, y));
}

void TrafficLight::draw() { 
    tools->window.draw(sprite);
}

TrafficLight::TrafficLight(Handler *_tools) : tools(_tools) {
    sprite.setTexture(_tools->resource_manager.get_texture("TRAFFIC_RED"));
}


