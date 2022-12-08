#include <SFML/Graphics.hpp>
#include "src/State.hpp"
#include "src/Handler.hpp"
#include "src/definition_library.hpp"
#include "src/GameState.hpp"

class AboutState : public State {

private:

	sf::Text button;
	sf::Text Title;
	sf::Text Paragraph;

	handler_ptr tools;

	sf::Texture background;
	sf::Sprite background_sprite;

public:

	AboutState() = default;
	~AboutState() = default;
	AboutState(handler_ptr _tools);

	void init(int status);
	void handle_input();
	void update(float dt);
	void draw(float dt);

	void pause() {};
	void resume() {};
};