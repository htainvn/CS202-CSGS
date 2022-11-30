#include "src/Animal.hpp"
#include "src/definition_library.hpp"

class Log : public floatObject {
public:
	Log() = default;

	Log(handler_ptr tools) : floatObject(tools) {}

	Log(handler_ptr tools, bool dir, Position pos, float _speed);

	void adjust();

	int get_type();

	void setCurrent(People*& people);

	~Log();

private:

	People* people = nullptr;

}; 
