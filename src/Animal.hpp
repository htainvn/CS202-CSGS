//
//  Animal.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 06/11/2022.
//

#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>
#include "src/ResourceManager.hpp"

class Animal {
private:
    sf::Sprite sprite;
    int pos_x;
public:
    Animal(ResourceManager& resource_manager) {}
    void go_to_position(int x) {}
};

#endif /* Animal_hpp */
