//
//  Pathway.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Pathway.hpp"

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
