#include "class.h"

cpeople::cpeople(double x, double y, bool alive, std::string type, double size)
{
    x_ = x;
    y_ = y;
    alive_ = alive;
    type_ = type;
    size_ = size;
}

cpeople::~cpeople(){}

std::string cpeople::type_path () const
{
    return type_;
}

double cpeople::Ox_coordinate() const
{
    return x_;
}

double cpeople::Oy_coordinate() const
{
    return y_;
}

bool cpeople::can_move_right()
{
    if (x_ + size_ >= x_res)
        return false;
    else
        return true;
}

bool cpeople::can_move_left()
{
    if (x_ <= 0)
        return false;
    else
        return true;
}

bool cpeople::can_move_down()
{
    if (y_ + 200 < y_res)
        return true;
    else
        return false;
}

void cpeople::move_right()
{
    if (can_move_right())
    {
        x_ = x_ + 100;
        type_ = "/Users/hovietbaolong/Desktop/crossing_road/Picture3.png";
    }
}
void cpeople::move_left()
{
    if (can_move_left())
    {
        x_ = x_ - 100;
        type_ = "/Users/hovietbaolong/Desktop/crossing_road/PICTURE 5.png";
    }
}

void cpeople::move_down()
{
    if (can_move_down())
    {
        y_ += 100;
        type_ = "/Users/hovietbaolong/Desktop/crossing_road/Picture2.png";
    }
}

void cpeople::change_type (std::string type)
{
    type_ = type;    
}

sf::Sprite set_character(const cpeople &character)
{
    sf::Sprite sp;
    sf::Texture image;
    if (!image.loadFromFile(character.type_path()))
    {
        std::cout << "image loading error!" << std::endl;
    }
    sp.setTexture(image);
    sf::Vector2f v(character.Ox_coordinate(), character.Oy_coordinate());
    sp.setPosition(v);
    return sp;
}
