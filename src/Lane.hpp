//
//  Lane.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Lane_hpp
#define Lane_hpp

#include <stdio.h>

#include "src/definition_library.hpp"
#include "src/Level.hpp"
#include "src/Handler.hpp"
#include "src/Vehicle.hpp"
#include "src/Animal.hpp"
#include "src/Position.hpp"
#include "src/People.hpp"

class Lane {
    
public:
    
/* CONSTRUCTORS & DESTRUCTORS*/
    
    Lane(handler_ptr _tools) : tools (_tools) {}
    
    Lane(handler_ptr _tools, float x, float y);
    
    Lane(handler_ptr _tools, Position pos);
    
    virtual ~Lane() {}
    
/* END HERE */
    
/*----------------------------------------------------------------------------------------*/
    
/* AVAILABLE FUNCTIONS FOR ALL SUB-CLASSESS */
    
    void change_image(sf::Texture& tex);
    
    void locate_at(float x, float y);
    
    Position position();
    
    bool out_scr();
    
    void set_current(People*& mario);
    
    void unset();
    
    bool is_current();
    
    int level();
    
    void set_level(const Level& lev);
    
/* END HERE */
    
/*----------------------------------------------------------------------------------------*/
    
/* VIRTUAL FUNCTIONS */
    
    virtual void draw();
    
    virtual std::vector<Sprite*> objects() { std::vector<Sprite*> dump; return dump; }
    
    virtual void adjust_objects();
    
    virtual int type() { return -1; }
    
    virtual void change_status(int _position = -1, int _dir = -1, int _bottom = -1, int _top = -1) {}
    
    virtual int direction() { return -1; }
    
    virtual void stop();
    
    virtual void slowdown() {}
    
    virtual void run() {}
    
/* END HERE */
    
protected:
    
    handler_ptr tools;
    
private:
    
    Sprite sprite;
    
    People* people;
    
    Level lev;
    
private:
    
    void draw_itself();
    
};

#endif /* Lane_hpp */
