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
    
    /*
    virtual int get_lane_type() { return 0; }
    virtual void allocate_lane_position( ResourceManager& resource_manager, float x, float y) { }
    virtual void adjust_objects() {}
    virtual std::vector<sf::Sprite> objects() { return std::vector<sf::Sprite>(0); }
    
    virtual void update_traffic(ResourceManager& resource_manager, int& cnt_time) {}
    virtual void stop_traffic() {}
    
    //for road only
    virtual int see_position() { return 0; }
    virtual int see_dir() { return 0; }
    virtual int see_bottom_type() { return 0; }
    virtual int see_top_type() { return 0;  }
    virtual std::string get_texture_code() {return "";}
    virtual void change_dir(int x) {}
    virtual void change_position(int x) {}
    virtual void change_bottom_type(int x) {}
    virtual void change_top_type(int x) {}
    virtual void change_texture(ResourceManager& resource_manager) {}
    virtual void add_vehicle(Vehicle*& vehicle) {}
    //
    
    
    // for river only
    virtual void add_log(Log*& log) {}
    virtual void add_animal(Animal*& animal) {}
    //
    */
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
