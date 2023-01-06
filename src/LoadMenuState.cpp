//
//  LoadMenuState.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 17/12/2022.
//

#include "LoadMenuState.hpp"

void LoadMenuState::update(float dt) {
    
    MenuState::btt_size = 0;
    
    getButtonSize();
    
    MenuState::buttonSelected = std::min(MenuState::buttonSelected, MenuState::btt_size);
    
    btt.resize(MenuState::btt_size);
    
    for (int i = 0; i < btt_size; i++) {
        btt[i].setFont(*font);
        btt[i].setCharacterSize(20);
        btt[i].setPosition(sf::Vector2f(SCREEN_WIDTH * 2 / 3 + 50, 300 + 25 * i));
        btt[i].setStyle(sf::Text::Regular);
        if (i != btt_size - 1) btt[i].setString("Data " + std::to_string(i));
        else btt[i].setString("Back to menu.");
        btt[i].setFillColor(sf::Color::White);
    }

    std::string tmp = btt[MenuState::buttonSelected].getString();
    
    if (tmp[0] == '>') tmp.erase(0, 5);
    
    btt[MenuState::buttonSelected].setStyle(sf::Text::Regular);
    
    btt[MenuState::buttonSelected].setString(tmp);
    
    btt[MenuState::buttonSelected].setFillColor(sf::Color::White);

    MenuState::buttonSelected += dt + btt_size + 1;
    
    MenuState::buttonSelected %= (btt_size + 1);

    btt[MenuState::buttonSelected].setString(">    " + btt[MenuState::buttonSelected].getString());
    
    btt[MenuState::buttonSelected].setFillColor(button_color[MenuState::buttonSelected]);
    
    btt[MenuState::buttonSelected].setStyle(sf::Text::Bold);
}

void LoadMenuState::getButtonSize() {
    std::string path = WORKING_DIR + "/datagame";
    
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        MenuState::btt_size++;
    }
    
    MenuState::btt_size--;
}

void LoadMenuState::draw(float dt)
{
    
    MenuState::tools->window.clear(sf::Color::Black);

    MenuState::tools->window.draw(MenuState::background_sprite);
    
    MenuState::tools->window.draw(MenuState::Title);

    for (int i = 0; i < btt_size; ++i) MenuState::tools->window.draw(btt[i]);

    MenuState::tools->window.display();
}

void LoadMenuState::handle_input() {
    sf::Event key_event;
    
    if (!MenuState::tools->window.pollEvent(key_event)) return;

    switch (key_event.type)
    {
        case (sf::Event::Closed):
            if (MenuState::tools->window.isOpen()) MenuState::tools->window.close();
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
                    if (MenuState::buttonSelected == btt_size - 1) MenuState::tools->state_manager.receive_delete_request();
                    else MenuState::tools->state_manager.receive_add_request(new GameLoadedState(MenuState::tools, MenuState::buttonSelected));
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
