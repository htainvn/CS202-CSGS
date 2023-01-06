//
//  LoadMenuState.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 17/12/2022.
//

#ifndef LoadMenuState_hpp
#define LoadMenuState_hpp

#include <stdio.h>
#include "src/MenuState.hpp"
#include "src/GameLoadedState.hpp"

class LoadMenuState : public MenuState {

public:
    LoadMenuState(Handler* _tools) : MenuState(_tools) {}
    void update(float dt);
    void draw(float dt);
    void handle_input();
    
private:
    void getDataCointainer();
    void getButtonDefaultStyle(const std::string &tmp);
    void getButtonActiveStyle();
    
private:
    
    std::vector<sf::Text> btt;

    std::vector<int> data_index;
    
    sf::Color button_color[7] = {sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White};
};

#endif /* LoadMenuState_hpp */
