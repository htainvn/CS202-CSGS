//
//  LostState.hpp
//  CROSSING_ROAD
//
//  Created by Hồ Việt Bảo Long on 07/12/2022.
//

#ifndef LostState_hpp
#define LostState_hpp

#include <SFML/Graphics.hpp>
#include "src/State.hpp"
#include "src/Handler.hpp"
#include "src/GameState.hpp"
#include "src/definition_library.hpp"
#include <string>

#define options 3
#define option1 "Try Again"
#define option2 "Menu"
#define option3 "Exit"


class LostMenu : public State{
private:
    sf::Sprite BackgroundSprite, HeadstoneSprite;
    handler_ptr resource_;
    sf::Text option [options];
    bool is_entered = false;
protected:
    int PointingButton_ = 0;
public:
    LostMenu(handler_ptr resource = nullptr) : resource_(resource){}
    ~LostMenu(){}

    void init(int status);
    void handle_input();
    void update(float dt);
    void draw (float dt);

    void pause() {};
    void resume() {};
};

#endif /* LostState_hpp */
