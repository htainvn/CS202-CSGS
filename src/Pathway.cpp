//
//  Pathway.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Pathway.hpp"

Pathway::Pathway(handler_ptr _tools, Level level) : Lane(_tools, level) {
    Lane::change_image(_tools->theme_controller.get("PAVEMENT"));
}

Pathway::Pathway(handler_ptr _tools, float x, float y, Level level) : Lane(_tools, x, y, level) {
    Lane::change_image(_tools->theme_controller.get("PAVEMENT"));
}

Pathway::Pathway(handler_ptr _tools, Position pos, Level level) : Lane(_tools, pos, level) {
    Lane::change_image(_tools->theme_controller.get("PAVEMENT"));
}



void Pathway::draw()
{
    
    Lane::draw();
    
}

void Pathway::save(std::ofstream& fout) {
    fout << type() << " " << is_current() << "\n";
    
    fout << level() << " " << lev.path_remain() << " " << lev.road_remain() << "\n";
    
    fout << position().get_x() << " " << position().get_y() << "\n";
}

void PathwayLight::draw()
{
    
    Lane::draw();
    
    light.draw();
    
}

void PathwayLight::adjust_objects()
{ 
    
    Lane::adjust_objects();
    
    light.locate_at(SCREEN_WIDTH - 200, Lane::position().get_y() - 70);
    
}

PathwayLight::PathwayLight(handler_ptr _tools, Level level) : Pathway(_tools, level)
{
    light = TrafficLight(_tools);
    
    light.locate_at(SCREEN_WIDTH - 200, Lane::position().get_y() - 70);
}

PathwayLight::PathwayLight(handler_ptr _tools, float x, float y, Level level) : Pathway(_tools, x, y, level)
{
    light = TrafficLight(_tools);
    
    light.locate_at(SCREEN_WIDTH - 200, Lane::position().get_y() - 70);
}

PathwayLight::PathwayLight(handler_ptr _tools, Position pos, Level level) : Pathway(_tools, pos, level)
{
    light = TrafficLight(_tools);
    
    light.locate_at(SCREEN_WIDTH - 200, Lane::position().get_y() - 70);
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

void PathwayLight::save(std::ofstream& fout) {
    fout << type() << " " << is_current() << "\n";
    
    fout << level() << " " << lev.path_remain() << " " << lev.road_remain() << "\n";
    
    fout << position().get_x() << " " << position().get_y() << "\n";
}
