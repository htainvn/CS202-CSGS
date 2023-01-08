//
//  StateManager.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/StateManager.hpp"

void StateManager::process_request() {
//    switch(this->syntax)
//    {
//        case -1:
//            break;
//        case 0: //add
//            if (!this->states_container.empty()) this->states_container.top()->pause();
//            this->states_container.push(std::move(received_state));
//            this->states_container.top()->init(0);
//            break;
//        case 1: //replace
//            if (!this->states_container.empty()) {
//                delete this->states_container.top();
//                this->states_container.pop();
//            }
//            this->states_container.push(std::move(received_state));
//            this->states_container.top()->init(0);
//            break;
//        case 2: //delete
//            if (!this->states_container.empty()) {
//                delete this->states_container.top();
//                this->states_container.pop();
//            }
//            if (!this->states_container.empty()) this->states_container.top()->resume();
//            break;
//    }
//    this->syntax = -1;
    
    if (clear) {
        while (!states_container.empty()) {
            state_ptr top = states_container.top();
            states_container.pop();
            delete top;
        }
        clear = false;
    }
    if (pop && !states_container.empty()) {
        delete states_container.top();
        states_container.pop();
        
        if (!states_container.empty())
            states_container.top()->resume();
        pop = false;
    }
    if (push) {
        if (replace && !states_container.empty()) {
            delete states_container.top();
            states_container.pop();
        }
        states_container.push(std::move(received_state));
        push = replace = false;
        states_container.top()->init(0);
    }
}

void StateManager::receive_add_request(state_ptr newState) {
    this->received_state = std::move(newState);
    push = true;
}

void StateManager::receive_replace_request(state_ptr newState) {
    this->received_state = std::move(newState);
    push = replace = true;
}

void StateManager::receive_delete_request() {
    pop = true;
}

void StateManager::receive_clear_request() {
    clear = true;
}

state_ptr StateManager::get_current_state() {
    return this->states_container.top();
}
