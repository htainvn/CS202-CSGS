//
//  GamePauseState.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 16/12/2022.
//

#include "GamePauseState.hpp"


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
                    case (sf::Keyboard::R):
                        tools->state_manager.receive_delete_request();
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

void GamePauseState::update() { 

}
