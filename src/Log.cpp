#include "Log.hpp"

Log::Log(handler_ptr tools, bool dir, Position pos, float _speed) : floatObject(tools, dir, pos, _speed) {
    sprite.setTexture(tools->theme_controller.get("LOG"));
}

void Log::adjust_objects()
{
    if(people && !people->is_moving())
    {
        people->go_to_position(position().get_x() + 25, position().get_y());
    }
}

int Log::get_type() {
	return 2;
}

void Log::setCurrent(People*& mario) {
	people = mario;
}

bool Log::isCurrent() {
    return (people != nullptr);
}

Log::~Log() {
}

void Log::unset() {
    people = nullptr;
}

Log::Log(Log* other) { 
    floatObject::operator=(*other);
    if (other->people) people = new People(*other->people);
}

