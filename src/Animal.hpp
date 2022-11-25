//
//  Animal.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 06/11/2022.
//

#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>
//#include "src/ResourceManager.hpp"
#include "src/definition_library.hpp"
#include "src/Handler.hpp"
#include "string"
#include "src/Position.hpp"

/*
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

class Croc : public Animal {
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
*/

class Animal {
    
public:
    
    /* CONSTRUCTORS & DESTRUCTORS */
    
    Animal() = default;
    
    Animal(handler_ptr _tools) : tools(_tools) {}
    
    Animal(handler_ptr _tools, bool dir, float y);
    
    virtual ~Animal() {}
    
    /* END HERE */
    
    void locate_at(float x, float y);
    
    Position position();
    
    //void sound();
    
private:
    
    Sprite sprite;
    
    Position pos;
    
    bool dir = 0;
    
    float speed = 0;
    
protected:
    
    handler_ptr tools;
    
};

class Hippo : public Animal {
public:
    
    /* CONSTRUCTORS & DESTRUCTORS */
    
    Hippo() = default;
    
    Hippo(handler_ptr _tools) : Animal(_tools) {}
    
    Hippo(handler_ptr _tools, bool dir, float y) : Animal(_tools, dir, y) {}
    
    ~Hippo() {}
    
    /* END HERE */
    
};

class Croc : public Animal {
public:
    
    /* CONSTRUCTORS & DESTRUCTORS */
    
    Croc() = default;
    
    Croc(handler_ptr _tools) : Animal(_tools) {}
    
    Croc(handler_ptr _tools, bool dir, float y) : Animal(_tools, dir, y) {}
    
    ~Croc() {}
    
    /* END HERE */
    
};


#endif /* Animal_hpp */
