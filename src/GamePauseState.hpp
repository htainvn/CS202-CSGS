//
//  GamePauseState.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 16/12/2022.
//

#ifndef GamePauseState_hpp
#define GamePauseState_hpp

#include <SFML/Graphics.hpp>
#include "src/State.hpp"
#include "src/definition_library.hpp"
#include "src/GameStateScreen.hpp"

#define choices 2
#define option4 "RESUME"
#define option5 "BACK TO MENU"

class GamePauseState : public State {
public:
    GamePauseState(handler_ptr resource, GameStateScreen* game) : tools(resource), game_(game){
    }
    
    void init(int status);
    
    void handle_input();
    
    void extracted(float dt);
    
    void update(float dt);
    
    void draw(float dt);
    
    void pause() {}
    
    void resume() {}
    
    void menuNagivator(float dt);
    
    ~GamePauseState() {
        if (font) {
            delete font;
            font = nullptr;
        }
        if (game_) {
            delete game_;
            game_ = nullptr;
        }
    }
    
private:
    GameStateScreen* game_;
    handler_ptr tools;
    sf::Font* font;
    sf::Sprite background;
    sf::Text option [choices];
    sf::Text title;
    bool is_entered = false;
    
protected:
    int PointingButton_ = 0;
};
#endif /* GamePauseState_hpp */
