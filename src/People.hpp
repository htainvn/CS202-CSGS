#ifndef People_hpp
#define People_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#define x_res 1000
#define y_res 700
#define dsize 100

class People
{
private:
    double x_,y_;
    bool alive_;
    std::string type_;
    double size_;
public:
    People(double x = x_res/2, double y = y_res - 400, bool alive = true, std::string type = "MARIO_FORWARD", double size = dsize);
    ~People();
    std::string type_path () const;
    sf::Vector2f get_position() const;
    bool can_move_right();
    bool can_move_left();
    bool can_move_down();
    void move_right();
    void move_left();
    void move_down();
    void change_type (std::string type);
    void go_to_position(int x, int y) {}
};

sf::Sprite set_character (const People &character);

bool is_collision(sf::Vector2f obs, sf::Vector2f character);

#endif /* People_hpp  */
