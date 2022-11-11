//
//  Animal.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 06/11/2022.
//

#include "Animal.hpp"

Animal::Animal(bool type, float pos_x) {
	this->type = type;
	this->pos_x = pos_x;
}

Hippo::Hippo(ResourceManager& resource_manager, bool type, float pos_x) : Animal(type, pos_x) {
	std::string hash_name;
	if (type) hash_name = "HIPPO_RIGHT";
	else hash_name = "HIPPO_LEFT";
	sprite.setTexture(resource_manager.get_texture(hash_name));
	sprite.setPosition(sf::Vector2f(pos_x,0));
}

Croc::Croc(ResourceManager& resource_manager, bool type, float pos_x) : Animal(type, pos_x) {
	std::string hash_name;
	if (type) hash_name = "CROC_RIGHT";
	else hash_name = "CROC_LEFT";
	sprite.setTexture(resource_manager.get_texture(hash_name));
	sprite.setPosition(sf::Vector2f(pos_x, 0));
}

sf::Sprite& Hippo::getSprite() {
	return sprite;
}

sf::Sprite& Croc::getSprite() {
	return sprite;
}

