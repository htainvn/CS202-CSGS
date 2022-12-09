//
//  Lane.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Lane.hpp"


void Lane::change_image(sf::Texture &tex)
{
    sprite.setTexture(tex);
}

Position Lane::position()
{
    return Position(sprite.getPosition().x, sprite.getPosition().y);
}

void Lane::locate_at(float x, float y)
{
    sprite.setPosition(sf::Vector2f(x, y));
}

void Lane::draw_itself()
{
    tools->window.draw(sprite);
}

void Lane::draw()
{
    draw_itself();
}

bool Lane::out_scr() { 
    return !((position().get_y() > -100) && (position().get_y() < SCREEN_HEIGHT));
}

Lane::Lane(handler_ptr _tools, float x, float y, Level level) : tools(_tools), lev(level) {
    locate_at(x, y);
}

Lane::Lane(handler_ptr _tools, Position pos, Level level) : tools(_tools), lev(level) {
    
    locate_at(pos.get_x(), pos.get_y());
}

void Lane::set_current(People*& mario, int type) {
    people = mario;
}

void Lane::adjust_objects() {
    if (people)
    {
        people->go_to_position(people->get_sprite().getPosition().x , position().get_y());
    }
}

void Lane::unset() { 
    people = nullptr;
}

bool Lane::is_current() { 
    return (people != nullptr);
}

int Lane::level() { 
    return lev.lev();
}

void Lane::set_level(const Level& lev) {
    this->lev = lev;
}

void Lane::stop() {
    
}

Position Lane::people_position() {
    return Position(people->get_position().x, people->get_position().y);
}

void Lane::loading(std::ifstream& fin)
{
    
}

