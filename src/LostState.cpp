//
//  LostState.cpp
//  CROSSING_ROAD
//
//  Created by Hồ Việt Bảo Long on 07/12/2022.
//

#include "LostState.hpp"


void LostMenu::init(int status) {
    font = new sf::Font();
    if (!font->loadFromFile(FONT_PATH_FILE)) {
        std::cout << "Error";
        return;
    }
    
    for (int i = 0; i < options; ++i) {
        option[i].setFont(*font);
        option[i].setCharacterSize(70);
        option[i].setPosition(sf::Vector2f(i*SCREEN_WIDTH/4, SCREEN_HEIGHT / 2));
        option[i].setStyle(sf::Text::Regular);
        option[i].setFillColor(sf::Color::White);
    }

    option[0].setFillColor(sf::Color::Blue);

    option[0].setString("TRY \nAGAIN");
    option[1].setString("MENU");
    option[2].setString("EXIT");

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
                case (sf::Keyboard::Right):
                    update(1);
                    break;
                case (sf::Keyboard::Left):
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
    resource_->window.draw(option[0]);
    resource_->window.draw(option[1]);
    resource_->window.draw(option[2]);
    resource_->window.display();
}




