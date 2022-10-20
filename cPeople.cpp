#include "cPeople.h"

People::People(double x_res, double y_res, double size, bool is_survive, std::string path)
{
    mx = x_res/2;
    my = y_res - 100;
    is_survive = true;
    type = path;
    msize = size;
    ox_unit = x_res/size;
    oy_unit = y_res/size;
}

bool People::move_right_check(double x_res)
{
    if (x_res - mx - msize > msize)
        return true;
    return false;
}

bool People::move_left_check()
{
    if (mx > msize)
        return true;
    return false;
}

void People::move_right(double x_res)
{
    if (move_right_check())
    {
        mx += msize;
    }
    else
    {
        mx = x_res - msize;
    }
}

void People::move_left()
{
    if (move_left_check())
    {
        mx -= msize;
    }
    else
    {
        mx = 0;
    }
}

void People::render(sf::RenderWindow *window)
{
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "icon.png");
    sf::Sprite sp(texture);
    sp.setPosition(mx, my);
    window->draw(sp);
    return sp;
}
