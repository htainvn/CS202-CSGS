#include "People.hpp"

People::People(double x, double y, bool alive, std::string type, double size)
{
    x_ = x;
    y_ = y;
    alive_ = alive;
    type_ = type;
    size_ = size;
}

People::~People(){}

std::string People::type_path () const
{
    return type_;
}

sf::Vector2f People::get_position() const
{
    sf::Vector2f vector;
    vector.x = x_;
    vector.y = y_;
    return vector;
}

bool People::can_move_right()
{
    if (x_ + size_ >= x_res)
        return false;
    else
        return true;
}

bool People::can_move_left()
{
    if (x_ <= 0)
        return false;
    else
        return true;
}

bool People::can_move_down()
{
    if (y_ + 200 < y_res)
        return true;
    else
        return false;
}

void People::move_right()
{
    if (can_move_right())
    {
        x_ = x_ + 100;
        type_ = "MARIO_RIGHT";
    }
}
void People::move_left()
{
    if (can_move_left())
    {
        x_ = x_ - 100;
        type_ = "MARIO_LEFT";
    }
}

void People::move_down()
{
    if (can_move_down())
    {
        y_ += 100;
        type_ = "MARIO_DOWNWARD";
    }
}

void People::change_type (std::string type)
{
    type_ = type;
}

sf::Sprite set_character(const People &character)
{
    sf::Sprite sp;
    sf::Texture image;
    if (!image.loadFromFile(character.type_path()))
    {
        std::cout << "image loading error!" << std::endl;
    }
    sp.setTexture(image);
    sf::Vector2f v = character.get_position();
    sp.setPosition(v);
    return sp;
}

bool is_collision(sf::Vector2f vector, sf::Vector2f character)
{
    if (vector.x >= character.x && vector.x <= character.x + 100 && vector.y == character.y)
    {
        return true;
    }
    return false;
}
