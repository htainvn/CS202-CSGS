//
//  GameLoadedState.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 17/12/2022.
//

#ifndef GameLoadedState_hpp
#define GameLoadedState_hpp

#include <stdio.h>
#include "src/GameState.hpp"

class GameLoadedState : public GameState {
public:
    
    GameLoadedState(Handler* _tools, int indexfile) : GameState(_tools) {
        filename = WORKING_DIR + "/datagame/" + "data_saved_" + std::to_string(indexfile) + ".txt";
    }
    
    void create_new(); //overriden
    
    //void update(float dt);
    
private:
    
    std::string filename = "";

};

#endif /* GameLoadedState_hpp */
