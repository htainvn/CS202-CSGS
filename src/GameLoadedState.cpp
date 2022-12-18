//
//  GameLoadedState.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 17/12/2022.
//

#include "GameLoadedState.hpp"

void GameLoadedState::create_new() {
    std::ifstream fin; fin.open(filename);
    
    // #theme loading# //
    GameState::tools->load_theme(fin);

    GameState::traffic->load(fin);
    
    // #people loading# //
    GameState::people->loading(fin);
    
    // #lane loading# //
    GameState::lane_gen->loading(fin, people);
    
    fin >> GameState::level >> GameState::is_pause >> GameState::lost_count >> GameState::mario_lost_count >> GameState::is_TouchBounder;
    
    fin.close();
}
