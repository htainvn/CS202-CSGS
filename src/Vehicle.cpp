//
//  Vehicle.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 06/11/2022.
//

#include <string.h>
#include <time.h>
#include "Vehicle.hpp"

const int car_number = 9;
const int MAX_SPEED = 36; // maximum speed

Vehicle::Vehicle(ResourceManager& resource_manager, int dir, int speed, int y )
{
	//srand(time(NULL));
	int car_index = rand() % car_number;
	this->velocity = speed;
	sprite.setTexture(resource_manager.get_texture(get_car_texture(dir, car_index)));
	sprite.setPosition(sf::Vector2f(0, y));
}

std::string Vehicle::get_car_texture(int dir, int index)
{
	// 0 left ; 1 right
	std::string result = "C";
	if (!dir) result += 'L'; else result += 'R';
	result += '_';
	result += char(48 + index);
	return result;
}

int Vehicle::see_velocity() 
{ 
	return velocity; 
}

void Vehicle::go_to_position( int x, int y )
{
	sprite.setPosition(sf::Vector2f(x, y));
}