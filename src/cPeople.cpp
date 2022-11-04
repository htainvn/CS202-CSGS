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

double cpeople::Ox_coordinate()
{
    return x_;
}

double cpeople::Oy_coordinate()
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

void cpeople::move_right()
{
    if (can_move_right())
        x_ = x_ + 100;
}
void cpeople::move_left()
{
    if (can_move_left())
        x_ = x_ - 100;
}

void cpeople::move_down()
{
    if (can_move_down())
    {
        y_ += 100;
        type_ = "mario_down.png";
    }
}
