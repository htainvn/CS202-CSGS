//
// 
//  Traffic.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 25/11/2022.
//

#include "Traffic.hpp"
#include <time.h>
#include <chrono>


void Traffic::timing() 
{ 
    clock.restart();
}

int Traffic::update() 
{
    
    int  res = 0;
    std::cout << current_time << ' ';
    
    //long long checkpoint1 = clock.getElapsedTime().asMicroseconds();
    checkpoint2 = clock.getElapsedTime().asMilliseconds();

    current_time += checkpoint2 - checkpoint1;
        
    if (current_time > 15000)
    {
        /*checkpoint1 = 0;*/
        
        timing();
        
        current_time = 0;
    }
    
    int current_time_FloatToInt = current_time;

    if (current_time <= 6000)
    {
        res = 0;
        
        light_circle.setFillColor(sf::Color::Red);

        count_down.setString(std::to_string((6000 - current_time_FloatToInt) / 1000));
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
        count_down.setString(std::to_string((15000 - current_time_FloatToInt) / 1000));
    }
    
    checkpoint1 = clock.getElapsedTime().asMilliseconds();
    
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
