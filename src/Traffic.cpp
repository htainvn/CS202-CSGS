//
// 
//  Traffic.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 25/11/2022.
//

#include "Traffic.hpp"


void Traffic::timing() 
{ 
    clock.restart();
}

int Traffic::update() 
{
    
    int  res = 0;
    
    long long checkpoint1 = clock.getElapsedTime().asMicroseconds();
    
    if (current_time > 15000)
    {
        checkpoint1 = 0;
        
        timing();
        
        current_time = 0;
    }
    
    if (current_time <= 6000)
    {
        res = 0;
        
        light_circle.setFillColor(sf::Color::Red);

        count_down.setString(std::to_string((6000 - current_time) / 1000));
    }
    else
    {
        if (current_time >= 14000)
        {
            res = 1;
            
            light_circle.setFillColor(sf::Color::Yellow);
        }
        else
        {
            res = 2;
            
            light_circle.setFillColor(sf::Color::Green);
        }
        count_down.setString(std::to_string((15000 - current_time) / 1000));
    }
    
    long long checkpoint2 = clock.getElapsedTime().asMicroseconds();
    
    this->current_time += (checkpoint2 - checkpoint1);
    
    return res;
}

void Traffic::init(sf::Font *font) 
{ 
    light_circle.setFillColor(sf::Color::Red);
    light_circle.setPosition(sf::Vector2f(10, 10));
    
    count_down.setPosition(sf::Vector2f(50, 13));
    count_down.setFont(*font);
    count_down.setCharacterSize(20);
    count_down.setStyle(sf::Text::Regular);
}

void Traffic::draw() 
{
    tools->window.draw(count_down);
    tools->window.draw(light_circle);
}

void Traffic::save(std::ofstream& fout) 
{
    fout << current_time << "\n";
}

void Traffic::load(std::ifstream& fin) 
{
    fin >> current_time;
}
