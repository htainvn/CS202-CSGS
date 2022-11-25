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
