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
#include "math.h"

class Lane {
    
public:
    
/* CONSTRUCTORS & DESTRUCTORS*/
    
    Lane(handler_ptr _tools, Level level) : tools (_tools), lev(level) {}
    
    Lane(handler_ptr _tools, float x, float y, Level level);
    
    Lane(handler_ptr _tools, Position pos, Level level);
    
    virtual ~Lane() {}
    
/* END HERE */
    
/*----------------------------------------------------------------------------------------*/
    
/* AVAILABLE FUNCTIONS FOR ALL SUB-CLASSESS */
    
    void change_image(sf::Texture& tex);
    
    void locate_at(float x, float y);
    
    Position position();
    
    bool out_scr();
    
    void set_level(const Level& lev);
    
    bool is_current();
    
    int level();
    
    Position people_position();
    
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
    
    virtual void set_current(People*& mario, int _type = 0);
    
    virtual bool check_lost(){return false;};
    
    virtual void unset();
    
    virtual void loading(std::ifstream& fin);

    virtual void save(std::ofstream & fout){}
    
/* END HERE */
    
protected:
    
    handler_ptr tools;

    Level lev;
    
private:
    
    Sprite sprite;
    
    People* people = nullptr;
    
private:
    
    void draw_itself();
    
};

#endif /* Lane_hpp */
