#pragma once

#include <SFML/Graphics.hpp>
#include "src/State.hpp"
#include "src/Handler.hpp"
#include "src/definition_library.hpp"
#include "src/GameState.hpp"
#include "src/AboutState.hpp"

class MenuState : public State {

public:
	
	MenuState() = default;
	~MenuState() = default;
	MenuState(handler_ptr _tools);

	virtual void init(int status);
	virtual void handle_input();
	virtual void update(float dt);
	virtual void draw(float dt);

	void pause() {};
	void resume() {};
    
protected:
    
    int btt_size = 4;
    
    sf::Font* titleFont = nullptr;
    
    sf::Text button[5];
    sf::Text Title;
    
    handler_ptr tools;
    int buttonSelected = 0;

    sf::Texture background;
    sf::Sprite background_sprite;

    sf::Color button_color[5];
};
