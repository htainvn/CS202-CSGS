//
//  GameState.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef GameStateScreen_hpp
#define GameStateScreen_hpp

#include <stdio.h>
#include "src/GameState.hpp"

class GameStateScreen : public GameState {
public:
    GameStateScreen(const GameState* base) : GameState(*base){}
    ~GameStateScreen(){}
    void draw();
};

#endif /* GameStateScreen_hpp */
