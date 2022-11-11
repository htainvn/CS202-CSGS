//
//  Pathway.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Pathway.hpp"

Pathway::Pathway(sf::Texture& texture) {
    this->sprite.setTexture(texture);
}

void Pathway::allocate_lane_position(float x, float y) {
    this->sprite.setPosition(sf::Vector2f(x, y));
}

int Pathway::get_lane_type() {
    return PATHWAY_TYPE;
}

int PathwayLight::get_lane_type() {
    return PATHWAYLIGHT_TYPE;
}

PathwayLight::PathwayLight(sf::Texture& texture_path, sf::Texture& texture_light) {
    this->sprite.setTexture(texture_path);
    this->light = TrafficLight(texture_light);
}

void PathwayLight::allocate_lane_position(float x, float y) {
    this->sprite.setPosition(sf::Vector2f(x, y));
    this->light.allocate_position(y);
}

void PathwayLight::adjust_objects() {
    this->light.allocate_position(this->sprite.getPosition().y);
}

std::vector<sf::Sprite> PathwayLight::all_relative_object() {
    std::vector<sf::Sprite> res;
    res.push_back(this->light.out_scr());
    return res;
}

void PathwayLight::update_traffic(ResourceManager& resource_manager, int status, sf::Clock& clock, sf::CircleShape& shape) {
    if (status == 0) {
        if (clock.getElapsedTime().asSeconds() >= 14) {
            this->light.turn_yellow(resource_manager.get_texture("TRAFFIC_YELLOW"));
            shape.setFillColor(sf::Color::Yellow);
        }
        else {
            this->light.turn_green(resource_manager.get_texture("TRAFFIC_GREEN"));
            shape.setFillColor(sf::Color::Green);
        }
    }
    else {
            this->light.turn_red(resource_manager.get_texture("TRAFFIC_RED"));
            shape.setFillColor(sf::Color::Red);
    }
}
