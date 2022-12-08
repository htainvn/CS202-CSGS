#include "src/MenuState.hpp"
#include "src/Position.hpp"
#include <iostream>

MenuState::MenuState(handler_ptr _tools) : tools(_tools) {};

void MenuState::init(int status) {
	
	font = new sf::Font();
	if (!font->loadFromFile(FONT_MENU_PATH_FILE)) {
		std::cout << "Error";
		return;
	}

	if (!background.loadFromFile(MENU_BACKGROUND_PATH_FILE)) {
		std::cout << "Error";
		return;
	}
	background.setSmooth(true);
	background_sprite = Sprite(background);

	Title.setFont(*font);
	Title.setCharacterSize(80);
	Title.setPosition(Vector2f(30, 150));
	Title.setStyle(sf::Text::Regular);
	Title.setFillColor(sf::Color(105, 105, 105));
	Title.setString("| CROSSING ROAD |");


	for (int i = 0; i < BUTTON; ++i) {
		button[i].setFont(*font);
		button[i].setCharacterSize(50);
		button[i].setPosition(sf::Vector2f(SCREEN_WIDTH * 2 / 3, 250 + 100 * i));
		button[i].setStyle(sf::Text::Regular);
		button[i].setFillColor(sf::Color::Transparent);
	}

	button_color[0] = sf::Color(255, 222, 173);
	button_color[1] = sf::Color(210, 180, 140);
	button_color[2] = sf::Color(188, 143, 143);
	button_color[3] = sf::Color(184, 134, 11);

	button[0].setFillColor(button_color[0]);

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
					if (buttonSelected == 2) {
						tools->state_manager.receive_add_request(new AboutState(this->tools));
					}
					if (buttonSelected == 3) {
						this->tools->window.close();
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
	button[buttonSelected].setFillColor(sf::Color::Transparent);

	buttonSelected += dt + BUTTON;
	buttonSelected %= BUTTON;

	button[buttonSelected].setFillColor(button_color[buttonSelected]);
}

void MenuState::draw(float dt) 
{
	tools->window.clear(sf::Color::Black);

	tools->window.draw(background_sprite);
	tools->window.draw(Title);

	for (int i = 0; i < BUTTON; ++i) tools->window.draw(button[i]);

	tools->window.display();
}