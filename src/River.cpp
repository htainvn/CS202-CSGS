//
//  River.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/River.hpp"

/*
int River::get_lane_type() {
    return RIVER_TYPE;
}

River::River(sf::Texture& texture) {
    sprite.setTexture(texture);
}

void River::allocate_lane_position(ResourceManager& resource_manager, float x, float y) {
    sprite.setPosition(sf::Vector2f(x,y));
    int num_of_animals = 1 + rand() % 7;
    spawn_animal(resource_manager,y, num_of_animals);
}

void River::adjust_objects() {
    for (auto i : animals) 
            i->go_to_position(0, this->sprite.getPosition().y, i->getType());
}

std::vector<sf::Sprite> River::all_relative_object() {
    std::vector<sf::Sprite> res;
    for (auto i : animals) res.push_back(i->getSprite());
    return res;
}

void River::spawn_animal(ResourceManager& resourcemanager, float y, int num_of_animals){
    bool i = rand() % 2;
    bool j = rand() % 2;
    Animal* animal = nullptr;
    for (int k = 0; k < num_of_animals; ++k) {
        if (i) {
            animal = new Hippo(resourcemanager, j, y);
        }
        else animal = new Croc(resourcemanager, j, y);
        animal->go_to_position(300 * (k + 1), y, j);
        animals.push_back(animal);
    }
}


River::~River() {
    for (int i = 0; i << animals.size(); ++i) delete animals[i];
}

*/




River::River(handler_ptr _tools, Position pos) : Lane(_tools, pos)
{
    Lane::change_image(tools->resource_manager.get_texture("RIVER"));
}

void River::stop() { 
    
}

void River::spawn()
{
    /*
    bool i = rand() % 2;
    bool j = rand() % 2;
    Animal* animal = nullptr;
    for (int k = 0; k < num_of_animals; ++k) {
        if (i) {
            animal = new Hippo(resourcemanager, j, y);
        }
        else animal = new Croc(resourcemanager, j, y);
        animal->go_to_position(300 * (k + 1), y, j);
        animals.push_back(animal);
    }
    */
}

void River::adjust_objects()
{
    
    Lane::adjust_objects();
    
    for (auto &log : logs)
    {
        //log->locate_at(log->)
    }
    
    for (auto &animal : animals)
    {
        animal->locate_at(animal->position().get_x(), Lane::position().get_y());
    }
    
}
