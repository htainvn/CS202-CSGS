#include "src/MenuState.hpp"
#include "src/Position.hpp"
#include <iostream>

MenuState::MenuState(handler_ptr _tools) : tools(_tools) {};

void MenuState::init(int status) {
	
	font = new sf::Font();
	if (!font->loadFromFile(FONT_PATH_FILE)) {
		std::cout << "Error";
		return;
	}

	for (int i = 0; i < BUTTON; ++i) {
		button[i].setFont(*font);
		button[i].setCharacterSize(70);
		button[i].setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / (BUTTON + 1) * (i + 1)));
		button[i].setStyle(sf::Text::Regular);
		button[i].setFillColor(sf::Color::White);
	}

	button[0].setFillColor(sf::Color::Blue);

	button[0].setString("PLAY");
	button[1].setString("OPTIONS");
	button[2].setString("ABOUT");
	button[3].setString("EXIT");

}

void MenuState::handle_input() {

	sf::Event key_event;
	
	if (!this->tools->window.pollEvent(key_event)) return;

	switch (key_event.type)
	{
		case (sf::Event::Closed):
			this->tools->window.close();
			break;
		case (sf::Event::KeyPressed):
			switch (key_event.key.code) {
				case (sf::Keyboard::Up):
					update(-1);
					break;
				case (sf::Keyboard::Down):
					update(1);
					break;
				case (sf::Keyboard::Escape):
					tools->window.close();
					break;
				case (sf::Keyboard::Enter):
					if (buttonSelected == 0) {
						tools->state_manager.receive_add_request(new GameState(this->tools));
					}
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

void MenuState::update(float dt) {
	button[buttonSelected].setFillColor(sf::Color::White);

	buttonSelected += dt + BUTTON;
	buttonSelected %= BUTTON;

	button[buttonSelected].setFillColor(sf::Color::Blue);
}

void MenuState::draw(float dt) 
{
	tools->window.clear();
	for (int i = 0; i < BUTTON; ++i) tools->window.draw(button[i]);

	tools->window.display();
}