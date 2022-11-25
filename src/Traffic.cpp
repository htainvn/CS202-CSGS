//
//  Traffic.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 25/11/2022.
//

#include "Traffic.hpp"


int Traffic::timing() { 
    clock.restart();
}

int Traffic::update() {
    
    int t, res = 0;
    
    t = clock.getElapsedTime().asMilliseconds();
        
    if (t > 15000)
    {
        timing();
        
        t = clock.getElapsedTime().asMilliseconds();
    }
    
    if (t <= 6000)
    {
        res = 0;
        
        light_circle.setFillColor(sf::Color::Red);
        
        count_down.setString(std::to_string((6000 - t) / 1000));
    }
    else
    {
        if (t >= 14000)
        {
            res = 1;
            
            light_circle.setFillColor(sf::Color::Yellow);
        }
        else
        {
            res = 2;
            
            light_circle.setFillColor(sf::Color::Green);
        }
        count_down.setString(std::to_string((15000 - t) / 1000));
    }
    return res;
}

int Traffic::init(sf::Font *font) { 
    light_circle.setFillColor(sf::Color::Red);
    light_circle.setPosition(sf::Vector2f(10, 10));
    
    count_down.setPosition(sf::Vector2f(50, 13));
    count_down.setFont(*font);
    count_down.setCharacterSize(20);
    count_down.setStyle(sf::Text::Regular);
}

void Traffic::draw() {
    tools->window.draw(count_down);
    tools->window.draw(light_circle);
}
