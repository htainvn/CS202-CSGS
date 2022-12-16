//
//  LostState.cpp
//  CROSSING_ROAD
//
//  Created by Hồ Việt Bảo Long on 07/12/2022.
//

#include "LostState.hpp"


void LostMenu::init(int status) {
    font = new sf::Font();
    if (!font->loadFromFile(FONT_MENU_PATH_FILE)) {
        std::cout << "Error";
        return;
    }
    
    BackgroundSprite.setTexture(resource_->theme_controller.get("LOST_SCREEN"));
    
    //HeadstoneSprite.setTexture(resource_->theme_controller.get("HEADSTONE"));
    
    //HeadstoneSprite.setPosition(sf::Vector2f(SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 100));
    
    option[0].setFillColor(sf::Color::Blue);
    option[0].setString(option1);
    option[1].setString(option2);
    option[2].setString(option3);
    
    for (int i = 0; i < options; i++) {
        option[i].setFont(*font);
        option[i].setCharacterSize(30);
        std::string str;
        if (i>0) str = option[i-1].getString();
        option[i].setPosition(sf::Vector2f(((i>0) ? (option[i-1].getPosition().x + (double)str.length()*15 + 150) : 180), SCREEN_HEIGHT/2 + 150));
        option[i].setStyle(sf::Text::Regular);
        option[i].setFillColor(sf::Color::White);
    }

}

void LostMenu::handle_input() {
    sf::Event event;
    
    if (!resource_->window.pollEvent(event)) return;

    switch (event.type)
    {
        case (sf::Event::Closed):
            resource_->window.close();
            break;
        case (sf::Event::KeyPressed):
            switch (event.key.code) {
                case (sf::Keyboard::Down):
                case (sf::Keyboard::S):
                    update(1);
                    break;
                case (sf::Keyboard::W):
                case (sf::Keyboard::Up):
                    update(-1);
                    break;
                case (sf::Keyboard::Enter):
                    is_entered = true;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    };
}

void LostMenu::update(float signal) {
    if (is_entered){
        switch (PointingButton_) {
            case 0:
                resource_->state_manager.receive_replace_request(new GameState(resource_));
                break;
            case 1:
                resource_->state_manager.receive_delete_request();
                resource_->state_manager.receive_delete_request();
                break;
            case 2:
                resource_->window.close();
                break;
            default:
                break;
        }
    }
    else{
        if(PointingButton_ + signal < 0 || PointingButton_ + signal >= options)return;
        option[PointingButton_].setFillColor(sf::Color::White);
        PointingButton_ += signal;
        option[PointingButton_].setFillColor(sf::Color::Blue);
    }
}

void LostMenu::draw(float dt) {
    resource_->window.clear();
    resource_->window.draw(BackgroundSprite);
    //resource_->window.draw(HeadstoneSprite);
    resource_->window.draw(option[0]);
    resource_->window.draw(option[1]);
    resource_->window.draw(option[2]);
    resource_->window.display();
}




