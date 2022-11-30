#include "Log.hpp"

Log::Log(handler_ptr tools, bool dir, Position pos, float _speed) : floatObject(tools, dir, pos, _speed) {
	sprite.setTexture(tools->resource_manager.get_texture("LOG"));
}

void Log::adjust_objects()
{
    if(people)
    {
        people->go_to_position(position().get_x() + 25, position().get_y() - 10);
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
	if (people) {
		delete people;
		people = nullptr;
	}
}

void Log::unset() {
    people = nullptr;
}
