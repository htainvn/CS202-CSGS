//
//  floatObject.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 06/11/2022.
//

#include "Animal.hpp"


floatObject::floatObject(handler_ptr _tools, bool _dir, Position p, float _speed) : tools(_tools), dir(_dir), pos(p), speed(_speed) {
	locate_at(p.get_x(), p.get_y());
}

void floatObject::locate_at(float x, float y) { 
    sprite.setPosition(sf::Vector2f(x, y));
	pos = Position(x, y);
}

void floatObject::move_left() {
	locate_at(pos.get_x() - speed / 1000.f, pos.get_y());
}

void floatObject::move_right() {
	locate_at(pos.get_x() + speed / 1000.f, pos.get_y());
}

void floatObject::set_speed(float _speed) {
	speed = _speed;
}

Position floatObject::position() {
    return pos;
}

void floatObject::draw() { 
    tools->window.draw(sprite);
}

void floatObject::stop() {
	speed = 0;
}

void floatObject::run(float speed) {
	this->speed = speed;
}

void floatObject::slowndown() {
	speed *= 0.2;
}

Hippo::Hippo(handler_ptr _tools, bool _dir, Position p, float _speed) : floatObject(_tools, _dir, p, _speed) {
    sprite.setTexture(tools->theme_controller.get(get_hash_name()));
	sound.setBuffer(tools->theme_controller.get_buffer(sound_hash_name));
}

std::string Hippo::get_hash_name() {
	std::string hash_name;
	if (!dir) {
		hash_name = "HIPPO_LEFT";
	}
	else {
		hash_name = "HIPPO_RIGHT";
	}
	return hash_name;
}

Croc::Croc(handler_ptr _tools, bool dir, Position p, float _speed) : floatObject(_tools, dir, p, _speed) {
	sprite.setTexture(tools->theme_controller.get(get_hash_name()));
	sound.setBuffer(tools->theme_controller.get_buffer(sound_hash_name));
}

std::string Croc::get_hash_name() {
	std::string hash_name;
	if (!dir) {
		hash_name = "CROC_LEFT";
	}
	else {
		hash_name = "CROC_RIGHT";
	}
	return hash_name;
}

int Hippo::get_type() {
	return 0;
}

int Croc::get_type() {
	return 1;
}

void Croc::tell() {
	sound.play();
}

Croc::Croc(Croc* other) {
    floatObject::operator=(*other);
    //*this = *other;
    sound = other->sound;
    
}


void Hippo::tell() {
	sound.play();
}

void floatObject::save(std::ofstream& fout)
{
	fout << this->get_type() << std::endl;
    
	fout << this->position().get_x() << std::endl;
}

floatObject &floatObject::operator=(const floatObject &other) {
    pos = other.pos;

    dir = other.dir;

    speed = other.speed;
    
    tools = other.tools;

    sprite = other.sprite;
    return *this;
}

Hippo::Hippo(Hippo* other){
    floatObject::operator=(*other);
    sound = other->sound;
    //*this = *other;
}
