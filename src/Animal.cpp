//
//  Animal.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 06/11/2022.
//

#include "Animal.hpp"

Animal::Animal(bool type) {
	this->type = type;
}

bool Animal::getType() {
	return type;
}

Hippo::Hippo(ResourceManager& resource_manager, bool type, float pos_y) : Animal(type) {
	this->pos_y = pos_y;
	std::string hash_name;
	pos_x = 850;
	if (type) {
		hash_name = "HIPPO_RIGHT";
		pos_x = 0;
	}
	else hash_name = "HIPPO_LEFT";
	sprite.setTexture(resource_manager.get_texture(hash_name));
	sprite.setPosition(sf::Vector2f(pos_x,pos_y));
}

Croc::Croc(ResourceManager& resource_manager, bool type, float pos_y) : Animal(type) {
	this->pos_y = pos_y;
	std::string hash_name;
	pos_x = 900;
	if (type) {
		hash_name = "CROC_RIGHT"; 
		pos_x = 0;
	}
	else hash_name = "CROC_LEFT";
	sprite.setTexture(resource_manager.get_texture(hash_name));
	sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

sf::Sprite& Hippo::getSprite() {
	return sprite;
}

sf::Sprite& Croc::getSprite() {
	return sprite;
}

void Croc::go_to_position(float x, float y, bool type) {
	if (type)
		pos_x += speed + x;
	else
		pos_x -= speed + x;
	sprite.setPosition(sf::Vector2f(pos_x, y));
}

void Hippo::go_to_position(float x, float y, bool type) {
	if (type)
		pos_x += speed + x;
	else
		pos_x -= speed + x;
	sprite.setPosition(sf::Vector2f(pos_x, y));
}

