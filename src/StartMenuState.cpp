//
//  StartMenuState.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 17/12/2022.
//

#include "StartMenuState.hpp"

void StartMenuState::handle_input() {
    sf::Event key_event;
    
    if (!MenuState::tools->window.pollEvent(key_event)) return;

    switch (key_event.type)
    {
        case (sf::Event::Closed):
            MenuState::tools->window.close();
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
                    MenuState::tools->window.close();
                    break;
                case (sf::Keyboard::Enter):
                    if (MenuState::buttonSelected == 0) {
                        MenuState::tools->state_manager.receive_add_request(new GameState(MenuState::tools));
                    }
                    if (MenuState::buttonSelected == 1) {
                        MenuState::tools->state_manager.receive_add_request(new LoadMenuState(MenuState::tools));
                    }
                    if (MenuState::buttonSelected == 2) {
                        MenuState::tools->state_manager.receive_add_request(new AboutState(MenuState::tools));
                    }
                    if (MenuState::buttonSelected == 3) {
                        MenuState::tools->window.close();
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
