//
//  LostState.cpp
//  CROSSING_ROAD
//
//  Created by Hồ Việt Bảo Long on 07/12/2022.
//

#include "LostState.hpp"


void LostMenu::init(int status) {
    font = new sf::Font();
    if (!font->loadFromFile(FONT_MENU_OPTION_PATH_FILE)) {
        std::cout << "Error";
        return;
    }
    
    BackgroundSprite.setTexture(resource_->theme_controller.get("LOST_SCREEN"));
    
    //HeadstoneSprite.setTexture(resource_->theme_controller.get("HEADSTONE"));
    
    //HeadstoneSprite.setPosition(sf::Vector2f(SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 100));
    
    option[0].setFillColor(sf::Color::White);
    option[0].setString(option1);
    option[1].setString(option2);
    option[2].setString(option3);
    
    for (int i = 0; i < options; i++) {
        option[i].setFont(*font);
        option[i].setCharacterSize(20);
        std::string str = option[i].getString();
        //std::cout << str.length() << "\n";
        int margin_left = 0;
        if (i == 0) margin_left = 308;
        else if (i == 1) margin_left = 330;
        else margin_left = 340;
        option[i].setPosition(sf::Vector2f(margin_left, 200 + 30 * i));
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
                case (sf::Keyboard::Up):
                case (sf::Keyboard::W):
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
        
        option[PointingButton_].setStyle(sf::Text::Regular);
        
        std::string tmp = option[PointingButton_].getString();
        
        if (tmp[0] == '>') {
            tmp.erase(0, 5);
            option[PointingButton_].setPosition(sf::Vector2f(option[PointingButton_].getPosition().x + 30, option[PointingButton_].getPosition().y));
        }
        
        if (tmp[tmp.size()-1] == '<') tmp.erase(tmp.size() - 5, 5);
        
        
        option[PointingButton_].setString(tmp);
        
        option[PointingButton_].setFillColor(sf::Color::White);
        
        PointingButton_ += signal;
        
        std::string tmp2 = option[PointingButton_].getString();
        
        tmp2 = ">    " + tmp2 + "    <";
        
        option[PointingButton_].setString(tmp2);
        
        option[PointingButton_].setFillColor(sf::Color::White);
        
        option[PointingButton_].setPosition(sf::Vector2f(option[PointingButton_].getPosition().x - 30, option[PointingButton_].getPosition().y));
        
        option[PointingButton_].setStyle(sf::Text::Bold);
    }
}

void LostMenu::draw(float dt) {
    resource_->window.clear();
    resource_->window.draw(BackgroundSprite);
    resource_->window.draw(option[0]);
    resource_->window.draw(option[1]);
    resource_->window.draw(option[2]);
    resource_->window.display();
}




