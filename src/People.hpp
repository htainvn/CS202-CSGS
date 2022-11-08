#ifndef People_hpp
#define People_hpp

#ifndef class_h
#define class_h


#endif /* class_h */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#define x_res 1000
#define y_res 700
#define dsize 100

class cpeople
{
private:
    double x_,y_;
    bool alive_;
    std::string type_;
    double size_;
public:
    cpeople(double x = x_res/2, double y = y_res - 400, bool alive = true, std::string type = "/Users/hovietbaolong/Documents/GitHub/CS202-CSGS/src_design/people/mario_forward.png", double size = dsize);
    ~cpeople();
    std::string type_path () const;
    sf::Vector2f get_position() const;
    bool can_move_right();
    bool can_move_left();
    bool can_move_down();
    void move_right();
    void move_left();
    void move_down();
    void change_type (std::string type);
};

sf::Sprite set_character (const cpeople &character);

bool is_collision(sf::Vector2f obs, sf::Vector2f character);

