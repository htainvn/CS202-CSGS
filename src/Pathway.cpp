//
//  Pathway.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Pathway.hpp"

/*
Pathway::Pathway(sf::Texture& texture) {
    this->sprite.setTexture(texture);
}

void Pathway::allocate_lane_position(ResourceManager& resource_manager, float x, float y) {
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

void PathwayLight::allocate_lane_position(ResourceManager& resource_manager, float x, float y) {
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

void PathwayLight::update_traffic(ResourceManager& resource_manager, int& cnt_time) {
    if (cnt_time >= RED_TIME_END) {
        if (cnt_time >= YELLOW_TIME_START) this->light.turn_yellow(resource_manager.get_texture("TRAFFIC_YELLOW"));
        else
            this->light.turn_green(resource_manager.get_texture("TRAFFIC_GREEN"));
    }
    else
        this->light.turn_red(resource_manager.get_texture("TRAFFIC_RED"));
}
*/

Pathway::Pathway(handler_ptr _tools) : Lane(_tools) {
    Lane::change_image(_tools->resource_manager.get_texture("PAVEMENT"));
}

Pathway::Pathway(handler_ptr _tools, float x, float y) : Lane(_tools, x, y) {
    Lane::change_image(_tools->resource_manager.get_texture("PAVEMENT"));
}

Pathway::Pathway(handler_ptr _tools, Position pos) : Lane(_tools, pos) {
    Lane::change_image(_tools->resource_manager.get_texture("PAVEMENT"));
}

void Pathway::draw()
{
    
    Lane::draw();
    
}

void PathwayLight::draw()
{
    
    Lane::draw();
    
    light.draw();
    
}

void PathwayLight::adjust_objects()
{ 
    
    Lane::adjust_objects();
    
    light.locate_at(800, Lane::position().get_y() - 70);
    
}

PathwayLight::PathwayLight(handler_ptr _tools) : Pathway(_tools)
{
    light = TrafficLight(_tools);
    
    light.locate_at(800, Lane::position().get_y() - 70);
}

PathwayLight::PathwayLight(handler_ptr _tools, float x, float y) : Pathway(_tools, x, y)
{
    light = TrafficLight(_tools);
    
    light.locate_at(800, Lane::position().get_y() - 70);
}

PathwayLight::PathwayLight(handler_ptr _tools, Position pos) : Pathway(_tools, pos)
{
    light = TrafficLight(_tools);
    
    light.locate_at(800, Lane::position().get_y() - 70);
}

void PathwayLight::stop()
{
    light.turn_red();
}

void PathwayLight::slowdown()
{
    light.turn_yellow();
}

void PathwayLight::run()
{
    light.turn_green();
}
