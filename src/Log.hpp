#include "src/Animal.hpp"
#include "src/definition_library.hpp"

class Log : public floatObject {
public:
	Log() = default;

	Log(handler_ptr tools) : floatObject(tools) {}

	Log(handler_ptr tools, bool dir, Position pos, float _speed);

	void adjust_objects();

	int get_type();

	void setCurrent(People*& people);
    
    bool isCurrent();
    
    void unset();

	~Log();

private:

	People* people = nullptr;

}; 
