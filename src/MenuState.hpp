#include <SFML/Graphics.hpp>
#include "src/State.hpp"
#include "src/Handler.hpp"
#include "src/definition_library.hpp"
#include "src/GameState.hpp"
#include "src/AboutState.hpp"

#define BUTTON 3

class MenuState : public State {

private:
	
	sf::Text button[BUTTON];
	sf::Text Title;
	
	handler_ptr tools;
	int buttonSelected = 0;

	sf::Texture background;
	sf::Sprite background_sprite;

	sf::Color button_color[BUTTON];

public:
	
	MenuState() = default;
	~MenuState() = default;
	MenuState(handler_ptr _tools);

	void init(int status);
	void handle_input();
	void update(float dt);
	void draw(float dt);

	void pause() {};
	void resume() {};
};