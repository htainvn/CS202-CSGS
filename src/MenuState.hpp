#include <SFML/Graphics.hpp>
#include "src/State.hpp"
#include "src/Handler.hpp"
#include "src/definition_library.hpp"
#include "src/GameState.hpp"

#define BUTTON 4

class MenuState : public State {

private:
	
	sf::Text button[BUTTON];
	handler_ptr tools;
	int buttonSelected = 0;

public:
	
	MenuState() = default;
	MenuState(handler_ptr _tools);
	~MenuState() = default;

	void init(int status);
	void handle_input();
	void update(float dt);
	void draw(float dt);

	void pause() {};
	void resume() {};
};