//
//  LoadMenuState.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 17/12/2022.
//

#include "LoadMenuState.hpp"

void LoadMenuState::getButtonDefaultStyle(const std::string &tmp) {
    btt[MenuState::buttonSelected].setStyle(sf::Text::Regular);
    
    btt[MenuState::buttonSelected].setString(tmp);
    
    btt[MenuState::buttonSelected].setFillColor(sf::Color::White);
}

void LoadMenuState::getButtonActiveStyle() {
    btt[MenuState::buttonSelected].setString(">    " + btt[MenuState::buttonSelected].getString());
    
    btt[MenuState::buttonSelected].setFillColor(button_color[MenuState::buttonSelected]);
    
    btt[MenuState::buttonSelected].setStyle(sf::Text::Bold);
}

void LoadMenuState::update(float dt) {
    
    data_index.clear();
    
    getDataCointainer();
    
    MenuState::btt_size = data_index.size();
    
    MenuState::buttonSelected = std::min(MenuState::buttonSelected, MenuState::btt_size);
    
    btt.resize(MenuState::btt_size);
    
    for (int i = 0; i < data_index.size(); i++) {
        btt[i].setFont(*font);
        btt[i].setCharacterSize(20);
        btt[i].setPosition(sf::Vector2f(SCREEN_WIDTH * 2 / 3 + 50, 300 + 25 * i));
        btt[i].setStyle(sf::Text::Regular);
        if (data_index.at(i) != -1) btt[i].setString("Data " + std::to_string(data_index.at(i)));
        else btt[i].setString("Menu");
        btt[i].setFillColor(sf::Color::White);
    }
    
    std::string tmp = btt[MenuState::buttonSelected].getString();
        
    if (tmp[0] == '>') tmp.erase(0, 5);
    
    getButtonDefaultStyle(tmp);

    MenuState::buttonSelected += dt + btt_size;
    
    MenuState::buttonSelected %= btt_size;

    getButtonActiveStyle();
}

void LoadMenuState::getDataCointainer() {
    
    std::string path = WORKING_DIR + "/datagame";
    
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::string path_entry = entry.path().string();
        path_entry.erase(path_entry.begin(), path_entry.begin() + path.length() + 1);
        if (path_entry.find("data_saved_") != std::string::npos) {
            data_index.push_back(path_entry[11] - '0');
        }
    }
    
    data_index.push_back(-1);
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
                    else MenuState::tools->state_manager.receive_add_request(new GameLoadedState(MenuState::tools,
                                                                                                 data_index[MenuState::buttonSelected]));
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
