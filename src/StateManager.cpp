//
//  StateManager.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/StateManager.hpp"

void StateManager::process_request() {
    switch(this->syntax) {
        case -1:
            break;
        case 0: //add
            if (!this->states_container.empty()) this->states_container.top()->pause();
            this->states_container.push(std::move(received_state));
            this->states_container.top()->init(0);
            break;
        case 1: //replace
            if (!this->states_container.empty()) this->states_container.pop();
            this->states_container.push(std::move(received_state));
            this->states_container.top()->init(0);
            break;
        case 2: //delete
            if (!this->states_container.empty()) this->states_container.pop();
            if (!this->states_container.empty()) this->states_container.top()->resume();
            break;
    }
    this->syntax = -1;
}

void StateManager::receive_add_request(state_ptr newState) {
    this->received_state = std::move(newState);
    this->syntax = 0;
}

void StateManager::receive_replace_request(state_ptr newState) {
    this->received_state = std::move(newState);
    this->syntax = 1;
}

void StateManager::receive_delete_request() {
    this->syntax = 2;
}

state_ptr StateManager::get_current_state() {
    return this->states_container.top();
}


