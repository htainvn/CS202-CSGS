//
//  StartMenuState.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 17/12/2022.
//

#ifndef StartMenuState_hpp
#define StartMenuState_hpp

#include <stdio.h>
#include "src/MenuState.hpp"
#include "src/LoadMenuState.hpp"

class StartMenuState : public MenuState {
public:
    StartMenuState(Handler* _tools) : MenuState(_tools) {}
    
    void handle_input();
    
};

#endif /* StartMenuState_hpp */
