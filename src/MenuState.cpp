#include "src/MenuState.hpp"
#include "src/Position.hpp"
#include <iostream>

MenuState::MenuState(handler_ptr _tools) : tools(_tools) {};

void MenuState::init(int status) {
	
	font = new sf::Font();
	if (!font->loadFromFile(FONT_MENU_OPTION_PATH_FILE)) {
		std::cout << "Error";
		return;
	}
    
    titleFont = new sf::Font();
    titleFont->loadFromFile(FONT_MENU_PATH_FILE);

	if (!background.loadFromFile(MENU_BACKGROUND_PATH_FILE)) {
		std::cout << "Error";
		return;
	}
	background.setSmooth(true);
	background_sprite = Sprite(background);

	Title.setFont(*titleFont);
	Title.setCharacterSize(30);
	Title.setPosition(Vector2f(40, 40));
	Title.setStyle(sf::Text::Regular);
	Title.setFillColor(/*sf::Color(105, 105, 105)*/ sf::Color::White);
	Title.setString("CROSSING\nROAD");


	for (int i = 0; i < btt_size; ++i) {
		button[i].setFont(*font);
		button[i].setCharacterSize(20);
		button[i].setPosition(sf::Vector2f(SCREEN_WIDTH * 2 / 3 + 50, 300 + 25 * i));
		button[i].setStyle(sf::Text::Regular);
		button[i].setFillColor(sf::Color::White);
	}

	button_color[0] = /*sf::Color(128, 128, 128)*/ sf::Color::White;
	button_color[1] = /*sf::Color(188, 143, 143)*/ sf::Color::White;
	button_color[2] = /*sf::Color(184, 134, 11)*/ sf::Color::White;
    button_color[3] = sf::Color::White;

	button[0].setFillColor(button_color[0]);

	button[0].setString("PLAY");
    button[1].setString("LOAD GAME");
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
                    if (buttonSelected == 1) {
                        //tools->state_manager.receive_add_request(new LoadMenuState(this->tools));
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
    std::string tmp = button[buttonSelected].getString();
    
    if (tmp[0] == '>') tmp.erase(0, 5);
    
    button[buttonSelected].setStyle(sf::Text::Regular);
    
    button[buttonSelected].setString(tmp);
    
	button[buttonSelected].setFillColor(sf::Color::White);

	buttonSelected += dt + btt_size;
	buttonSelected %= btt_size;

    button[buttonSelected].setString(">    " + button[buttonSelected].getString());
    
	button[buttonSelected].setFillColor(button_color[buttonSelected]);
    
    button[buttonSelected].setStyle(sf::Text::Bold);
}

void MenuState::draw(float dt) 
{
	tools->window.clear(sf::Color::Black);

	tools->window.draw(background_sprite);
	tools->window.draw(Title);

	for (int i = 0; i < btt_size; ++i) tools->window.draw(button[i]);

	tools->window.display();
}
