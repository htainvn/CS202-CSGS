//
//  GameState.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "GameStateScreen.hpp"
void GameStateScreen::draw(){
    
    for (int i = 8; i >= 0; i--)
    {
        if (!lane_gen->at(i)->out_scr())
        {
            lane_gen->at(i)->draw();
        }
    }
    
    tools->window.draw(people->get_sprite());
    
    tools->window.draw(t_lev);
    
    traffic->draw();
    
}
