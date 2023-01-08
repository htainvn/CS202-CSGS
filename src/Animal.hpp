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
    
    virtual bool isCurrent() {return 0;}
    
    virtual void unset() {}
    
    virtual void adjust_objects() {}

    virtual void tell(){}

    void locate_at(float x, float y);
    
    Position position();

    void move_right();

    void move_left();
    
    void set_speed(float _speed);
    
    void draw();

    void stop();

    void slowndown();

    void run(float speed);
    
    void save(std::ofstream& fout);
    
    virtual bool is_animal() { return 0;}
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
    
    ~Hippo() {
        sound.stop();
    }

    int get_type();

    bool is_animal() { return 1;}

    void tell();
    
    /* END HERE */
private:
    std::string get_hash_name();

    sf::Sound sound;

    std::string sound_hash_name = "ZOMBIE_SOUND";
};

class Croc : public floatObject {
public:
    
    /* CONSTRUCTORS & DESTRUCTORS */
    
    Croc() = default;
    
    Croc(handler_ptr _tools) : floatObject(_tools) {}
    
    Croc(handler_ptr _tools, bool dir, Position p, float _speed);// : floatObject(_tools, dir, y) {}
    
    ~Croc() {
        sound.stop();
    }

    int get_type();

    bool is_animal() { return 1;}

    void tell();
    
    /* END HERE */
private:
    std::string get_hash_name();

    sf::Sound sound;

    std::string sound_hash_name = "CROC_SOUND";
    
};


#endif /* floatObject_hpp */
