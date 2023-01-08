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
#include <fstream>

class Traffic {
public:
    
/* CONSTRUCTORS & DESTRUCTORS */
    Traffic() = default;
    Traffic(handler_ptr _tools) : tools(_tools) {}
    Traffic(const Traffic& other){
        *this = other;
    }
    ~Traffic() {}
    
/* END */
    
/* BEHAVIOUR */
    
    int update(int pause = 0);
    
    void init(sf::Font *font);
    
    void draw();
    
    void save(std::ofstream& fout);
    
    void load(std::ifstream& fin);
/* END */
    
private:
    handler_ptr tools;
    
    sf::CircleShape light_circle = sf::CircleShape(15.f);
    
    sf::Text count_down;
    
    sf::Clock clock;
    
    float current_time = 0;

    long long checkpoint2 = 0;

    long long checkpoint1 = 0;

private:

    void timing();
    
};

#endif /* Traffic_hpp */
