//
//  GamePauseState.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 16/12/2022.
//

#include "src/GamePauseState.hpp"
#include "src/StartMenuState.hpp"
#include "src/MenuState.hpp"


void GamePauseState::init(int status){
    font = new sf::Font();
    if (!font->loadFromFile(FONT_MENU_OPTION_PATH_FILE)) {
        std::cout << "Error";
        return;
    }
    
    background.setTexture(tools->theme_controller.get("BLACKBOARD"));
    background.scale(sf::Vector2f(1,0.75));
    background.setPosition(sf::Vector2f(SCREEN_WIDTH/2 - 200, SCREEN_HEIGHT/2 - 100));
    
    title.setString("Pause");
    title.setFont(*font);
    title.setCharacterSize(20);
    title.setPosition(sf::Vector2f(310, 300));
    title.setStyle(sf::Text::Bold);
    title.setFillColor(sf::Color::White);
    
    
    option[0].setString(option4);
    option[1].setString(option5);
    for (int i=0; i<2; i++){
        option[i].setFont(*font);
        option[i].setCharacterSize(20);
        option[i].setPosition(sf::Vector2f(280, 350 + 30*i));
        option[i].setStyle(sf::Text::Regular);
        option[i].setFillColor(sf::Color::White);
    }
}

void GamePauseState::handle_input() { 
    sf::Event key_event;
    
    if (this->tools->window.pollEvent(key_event))
    {
        switch(key_event.type)
        {
            case (sf::Event::Closed):
            {
                this->tools->window.close();
                break;
            }
            case (sf::Event::KeyPressed):
            {
                switch (key_event.key.code) {
                    case (sf::Keyboard::Up):
                    case (sf::Keyboard::W):
                        update(-1);
                        break;
                    case (sf::Keyboard::Down):
                    case (sf::Keyboard::S):
                        update(1);
                        break;
                    case (sf::Keyboard::Enter):
                        is_entered = true;
                        break;
                    default:
                        break;
                }
            }
            default:
                break;
        }
    }
    
}

void GamePauseState::update(float dt) {
    if (is_entered){
        switch (PointingButton_) {
            case 0:
                tools->state_manager.receive_delete_request();
                break;
            case 1:
                tools->state_manager.receive_clear_request();
                tools->state_manager.receive_add_request(new StartMenuState(this->tools));
                break;
            default:
                break;
        }
    }
    else{
        if(PointingButton_ + dt < 0 || PointingButton_ + dt >= choices) return;
        
        option[PointingButton_].setStyle(sf::Text::Regular);
        
        std::string tmp = option[PointingButton_].getString();
        
        if (tmp[0] == '>') {
            tmp.erase(0, 5);
            option[PointingButton_].setPosition(sf::Vector2f(option[PointingButton_].getPosition().x + 30, option[PointingButton_].getPosition().y));
        }
        
        if (tmp[tmp.size()-1] == '<') tmp.erase(tmp.size() - 5, 5);
        
        
        option[PointingButton_].setString(tmp);
        
        option[PointingButton_].setFillColor(sf::Color::White);
        
        PointingButton_ += dt;
        
        std::string tmp2 = option[PointingButton_].getString();
        
        tmp2 = ">    " + tmp2 + "    <";
        
        option[PointingButton_].setString(tmp2);
        
        option[PointingButton_].setFillColor(sf::Color::White);
        
        option[PointingButton_].setPosition(sf::Vector2f(option[PointingButton_].getPosition().x - 30, option[PointingButton_].getPosition().y));
        
        option[PointingButton_].setStyle(sf::Text::Bold);
    }
}

void GamePauseState::draw(float dt){
    tools->window.clear();
    game_->draw();
    tools->window.draw(background);
    tools->window.draw(title);
    tools->window.draw(option[0]);
    tools->window.draw(option[1]);
    tools->window.display();
}
