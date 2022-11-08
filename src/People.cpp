#include "People.hpp"

People::People(ResourceManager& resource_manager, bool alive, std::string type)
{
    sp.setTexture(resource_manager.get_texture(type));
    sp.setPosition(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT - 300));
    alive_ = alive;
    type_ = type;
}

People::~People(){}

std::string People::type_path () const
{
    return type_;
}

void People::go_to_position(int x, int y)
{
    sp.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f People::get_position() const
{
    return sp.getPosition();
}

bool People::can_move_right()
{
    sf::Vector2f v = sp.getPosition();
    if (v.x + dsize>= SCREEN_WIDTH)
        return false;
    else
        return true;
}

bool People::can_move_left()
{
    sf::Vector2f v = sp.getPosition();
    if (v.x <= 0)
        return false;
    else
        return true;
}

bool People::can_move_down()
{
    sf::Vector2f v = sp.getPosition();
    if (v.y + 200 < SCREEN_HEIGHT)
        return true;
    else
        return false;
}

void People::move_right(ResourceManager& resource_manager)
{
    sf::Vector2f v = sp.getPosition();
    if (can_move_right())
    {
        sp.setPosition(sf::Vector2f(v.x + 100, v.y));
        type_ = "MARIO_RIGHT";
        sp.setTexture(resource_manager.get_texture(type_));
    }
}
void People::move_left(ResourceManager& resource_manager)
{
    sf::Vector2f v = sp.getPosition();
    if (can_move_left())
    {
        sp.setPosition(sf::Vector2f(v.x - 100, v.y));
        type_ = "MARIO_LEFT";
        sp.setTexture(resource_manager.get_texture(type_));
    }
}

void People::move_down(ResourceManager& resource_manager)
{
    sf::Vector2f v = sp.getPosition();
    if (can_move_down())
    {
        sp.setPosition(sf::Vector2f(v.x, v.y + 100));
        type_ = "MARIO_DOWNWARD";
        sp.setTexture(resource_manager.get_texture(type_));
    }
}

void People::change_type (std::string type)
{
    type_ = type;
}

sf::Sprite People::get_sprite () const{
    return sp;
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
