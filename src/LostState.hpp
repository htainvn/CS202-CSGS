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
#define option1 "TRY AGAIN"
#define option2 "MENU"
#define option3 "EXIT"

class LostMenu : public State {
private:
    sf::Sprite BackgroundSprite, HeadstoneSprite;
    handler_ptr resource_;
    sf::Text option [options];
    sf::Text recording;
    bool is_entered = false;
protected:
    int PointingButton_ = 0;
public:
    LostMenu(handler_ptr resource = nullptr) : resource_(resource){
        sf::View defaultView;
        defaultView.setCenter(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
        defaultView.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
        resource_->window.setView(defaultView);
    }
    ~LostMenu(){
        
    }

    void init(int status);
    void handle_input();
    void update(float dt);
    void draw (float dt);

    void pause() {};
    void resume() {};
};

#endif /* LostState_hpp */
