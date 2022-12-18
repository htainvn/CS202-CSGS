//
//  GamePauseState.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 16/12/2022.
//

#ifndef GamePauseState_hpp
#define GamePauseState_hpp

#include <stdio.h>
#include "src/GameState.hpp"

class GamePauseState : public GameState {
private:
    Handler* tools;
public:
    GamePauseState(Handler* _tools) : GameState(_tools) {}
    void handle_input();
    void update();
};

#endif /* GamePauseState_hpp */
