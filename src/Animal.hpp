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
    bool type; 
public:
    Animal(){}
    virtual void go_to_position(float x, float y, bool type) {}
    Animal(bool type);
    virtual sf::Sprite& getSprite() { sf::Sprite dummy; return dummy; }
    bool getType();
};

class Hippo :public Animal {
private:
    //sound
    float pos_x;
    float pos_y;
    float speed = 0.08;
    sf::Sprite sprite;
public:
    Hippo(){}
    void go_to_position(float x, float y, bool type);
    Hippo(ResourceManager& resource_manager,bool type, float pos_y);
    sf::Sprite& getSprite();
};

class Croc :public Animal {
private:
    //sound
    float pos_x;
    float pos_y;
    float speed = 0.03;
    sf::Sprite sprite;
public:
    Croc() {}
    void go_to_position(float x, float y, bool type);
    Croc(ResourceManager& resource_manager, bool type, float pos_y);
    sf::Sprite& getSprite();
};

#endif /* Animal_hpp */
