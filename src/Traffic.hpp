//
//  Traffic.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 25/11/2022.
//

#ifndef Traffic_hpp
#define Traffic_hpp

#include <SFML/Graphics.hpp>
#include "src/Handler.hpp"
#include "src/definition_library.hpp"
#include <stdio.h>

class Traffic {
public:
    
/* CONSTRUCTORS & DESTRUCTORS */
    
    Traffic(handler_ptr _tools) : tools(_tools) {};
    
    ~Traffic() {}
    
/* END */
    
/* BEHAVIOUR */
    int timing();
    
    int update();
    
    int init(sf::Font *font);
    
    void draw();
/* END */
    
private:
    handler_ptr tools;
    
    sf::CircleShape light_circle = sf::CircleShape(15.f);
    
    sf::Text count_down;
    
    sf::Clock clock;
private:
};

#endif /* Traffic_hpp */
