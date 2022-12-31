//
//  StateManager.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef StateManager_hpp
#define StateManager_hpp

#include <stack>
#include <stdio.h>

#include "src/State.hpp"

#include "src/definition_library.hpp"

class StateManager {
    
private:
    std::stack<state_ptr> states_container;
    state_ptr received_state;
    int syntax;
    
    
public:
    StateManager() {
        states_container = std::stack<state_ptr>();
        received_state = nullptr;
        syntax = -1;
    }
    
    void process_request();
    
    void receive_add_request(state_ptr newState);
    
    void receive_replace_request(state_ptr newState);
    
    void receive_delete_request();
    
    state_ptr get_current_state();
    
    ~StateManager() {
        while (!states_container.empty()) {
            delete states_container.top();
            states_container.top() = nullptr;
            states_container.pop();
        }
        
    }
};

#endif /* StateManager_hpp */
