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
#include"definition_library.hpp"
#include"string"

class Animal {
private:
    float pos_x;
    bool type; //0:left  1:right
public:
    Animal(){}
    void go_to_position(int x) {}
    Animal(bool type, float pos_x);
    virtual sf::Sprite& getSprite() { sf::Sprite dummy; return dummy; }
};

class Hippo :public Animal {
private:
    //sound
    sf::Sprite sprite;
public:
    Hippo(){}
    Hippo(ResourceManager& resource_manager,bool type, float pos_x);
    sf::Sprite& getSprite();
};

class Croc :public Animal {
private:
    //sound
    sf::Sprite sprite;
public:
    Croc() {}
    Croc(ResourceManager& resource_manager, bool type, float pos_x);
    sf::Sprite& getSprite();
};

#endif /* Animal_hpp */
