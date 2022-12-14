#include "src/AboutState.hpp"
#include "src/Position.hpp"
#include <iostream>

AboutState::AboutState(handler_ptr _tools) : tools(_tools) {};

void AboutState::init(int status) {

	font = new sf::Font();
	if (!font->loadFromFile(FONT_MENU_ABOUT_PATH_FILE)) {
		std::cout << "Error";
		return;
	}

	if (!background.loadFromFile(ABOUT_BACKGROUND_PATH_FILE)) {
		std::cout << "Error";
		return;
	}
	background.setSmooth(true);
	background_sprite = Sprite(background);

	// Define title
	Title.setFont(*font);
	Title.setCharacterSize(50);
	Title.setPosition(Vector2f(270, 50));
	Title.setStyle(sf::Text::Regular);
	Title.setFillColor(sf::Color::White);
	Title.setString("ABOUT");

	// Define button return
	button.setFont(*font);
	button.setCharacterSize(40);
	button.setPosition(Vector2f(500, 580));
	button.setStyle(sf::Text::Regular);
	button.setFillColor(sf::Color::White);
	button.setString("RETURN");

	// Define paragpaph
	Paragraph.setFont(*font);
	Paragraph.setCharacterSize(20);
	Paragraph.setPosition(Vector2f(100,170));
	Paragraph.setStyle(sf::Text::Regular);
	Paragraph.setFillColor(sf::Color::White);
	sf::String para = "";
	para += "- Using arrow button to move your character. \n \n";
	para += "- Using W A S D buttons to move your charater. \n \n";
	para += "- At the start of game you can change theme by pressing R. \n \n";
	para += "- The number of cars in each level is equal to the current level. \n \n";
	para += "- There are many traffic lights that you can utilize. \n \n";
	para += "- Our game has many themes for gameplay, try it yourself :3 \n";
	Paragraph.setString(para);
}

void AboutState::handle_input() {

	sf::Event key_event;

	if (!this->tools->window.pollEvent(key_event)) return;

	switch (key_event.type)
	{
	case (sf::Event::Closed):
		this->tools->window.close();
		break;
	case (sf::Event::KeyPressed):
		switch (key_event.key.code) {
		case (sf::Keyboard::Escape):
			tools->window.close();
			break;
		case (sf::Keyboard::Enter):
			tools->state_manager.receive_delete_request();
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void AboutState::update(float dt) {}

void AboutState::draw(float dt)
{
	tools->window.clear(sf::Color::Black);

	tools->window.draw(background_sprite);
	tools->window.draw(Title);
	tools->window.draw(Paragraph);
	tools->window.draw(button);
	

	tools->window.display();
}
