//
//  River.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/River.hpp"

int River::get_lane_type() {
    return RIVER_TYPE;
}

River::River(sf::Texture& texture) {
    sprite.setTexture(texture);
}

void River::allocate_lane_position(ResourceManager& resource_manager, float x, float y) {
    sprite.setPosition(sf::Vector2f(x,y));
    spawn_animal(resource_manager,x);
}

void River::adjust_objects() {
    for (auto i : animals) 
        i->go_to_position(this->sprite.getPosition().x, this->sprite.getPosition().y,i->getType());
}

std::vector<sf::Sprite> River::all_relative_object() {
    std::vector<sf::Sprite> res;
    for (auto i : animals) res.push_back(i->getSprite());
    return res;
}

void River::spawn_animal(ResourceManager& resourcemanager, float x){
    bool i = rand() % 2;
    bool j = rand() % 2;
    Animal* animal = nullptr;
    std::cout << i << " " << j;
    if (i) {
        animal = new Hippo(resourcemanager, j, x);
    }
    else animal = new Croc(resourcemanager, j, x);
    animals.push_back(animal);
}


River::~River() {
    for (int i = 0; i << animals.size(); ++i) delete animals[i];
}

