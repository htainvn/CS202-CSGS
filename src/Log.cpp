#include "Log.hpp"

Log::Log(handler_ptr tools, bool dir, Position pos, float _speed) : floatObject(tools, dir, pos, _speed) {
	sprite.setTexture(tools->resource_manager.get_texture("LOG"));
}

void Log::adjust() {

}

int Log::get_type() {
	return 2;
}

void Log::setCurrent(People*& mario) {
	people = mario;
}

Log::~Log() {
	if (people) {
		delete people;
		people = nullptr;
	}
}
