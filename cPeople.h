#ifndef cPeople_h
#define cPeople_h


#endif /* cPeople_h */

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

class People
{
private:
    double mx, my, msize, ox_unit, oy_unit;
    bool is_survive;
    std::string type;
public:
    People(double x_res = 720, double y_res = 1280, double size = 100, bool is_survive = true, std::string path = resourcePath() + "icon.png");
    //~People();
    //check whether character is able to move in screen or not
    bool move_right_check(double x_res = 720);
    bool move_left_check();
    bool move_down_check();
    bool move_ahead_check();
    //movement actions
    void move_right(double x_res = 720);
    void move_left();
    void move_down();
    void move_ahead();
    void render(sf::RenderWindow *window);
    //check if character collide with obstacle
    bool is_collision(std::vector<double> coors);
    //check status
    bool is_dead();
    //change character image (optional)
    void change_type(std::string path);
    // load and save current position of character to resume game
    void load_pos(std::string path);
    void save_pos(std::string path);
    //reset to original positions (new game)
    void reset();
};
