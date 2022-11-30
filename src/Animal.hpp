//
//  floatObject.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 06/11/2022.
//

#ifndef floatObject_hpp
#define floatObject_hpp

#include <stdio.h>
#include "src/definition_library.hpp"
#include "src/Handler.hpp"
#include "string"
#include "src/Position.hpp"
#include "src/People.hpp"


class floatObject {
    
public:
    
    /* CONSTRUCTORS & DESTRUCTORS */
    
    floatObject() = default;
    
    floatObject(handler_ptr _tools) : tools(_tools) {}
    
    floatObject(handler_ptr _tools, bool dir, Position p, float _speed);
    
    virtual ~floatObject(){}
    
    /* END HERE */
    
    virtual int get_type() { return 0; }

    virtual void setCurrent(People*& people) {}

    void locate_at(float x, float y);
    
    Position position();

    void move_right();

    void move_left();
    
    void set_speed(float _speed);
    
    void draw();
    //void sound();
    
    
protected:
    
    Position pos;

    bool dir = 0;

    float speed = 0;
    
    handler_ptr tools;

    sf::Sprite sprite;
    
};

class Hippo : public floatObject {
public:
    
    /* CONSTRUCTORS & DESTRUCTORS */
    
    Hippo() = default;
    
    Hippo(handler_ptr _tools) : floatObject(_tools) {}
    
    Hippo(handler_ptr _tools, bool dir, Position p, float _speed);// : floatObject(_tools, dir, y) {}
    
    ~Hippo() {}

    int get_type();
    
    /* END HERE */
private:
    std::string get_hash_name();
};

class Croc : public floatObject {
public:
    
    /* CONSTRUCTORS & DESTRUCTORS */
    
    Croc() = default;
    
    Croc(handler_ptr _tools) : floatObject(_tools) {}
    
    Croc(handler_ptr _tools, bool dir, Position p, float _speed);// : floatObject(_tools, dir, y) {}
    
    ~Croc() {}

    int get_type();

    
    /* END HERE */
private:
    std::string get_hash_name();
    
};


#endif /* floatObject_hpp */
