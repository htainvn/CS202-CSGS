//
//  Game.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Game.hpp"

Game::Game() {
    this->machine->window.create(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "CROSSING ROAD", sf::Style::Close);
    
    this->machine->state_manager.receive_add_request(new StartMenuState(this->machine));
    
    this->run();
}

void Game::frame_refresh(float& currentTime, float& runningTime) {
    float nextTime = this->game_clock.getElapsedTime().asSeconds();
    
    float dis = nextTime - currentTime;
    
    dis = std::min(0.25f, dis);
    runningTime += dis;
    
    while (runningTime >= FRAME_RATE_SECOND) {
        this->machine->state_manager.get_current_state()->update(FRAME_RATE_SECOND);
        this->machine->state_manager.get_current_state()->draw(FRAME_RATE_SECOND);
        this->machine->state_manager.get_current_state()->handle_input();
        runningTime -= FRAME_RATE_SECOND;
    }
    
    currentTime = nextTime;
}

void Game::run() {
    float currentTime = this->game_clock.getElapsedTime().asSeconds();
    float runningTime = 0.0f;
    
    while (this->machine->window.isOpen()) {
        sf::View defaultView;
        defaultView.setCenter(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
        defaultView.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
        this->machine->window.setView(defaultView);
        this->machine->state_manager.process_request();
        this->frame_refresh(currentTime, runningTime);
    }
    
    float interpolator = runningTime / FRAME_RATE_SECOND;
    this->machine->state_manager.get_current_state()->draw(interpolator);
}

Game::~Game() {
    if (machine) {
        delete machine;
    }
}
