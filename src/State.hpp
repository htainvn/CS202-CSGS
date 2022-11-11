//
//  State.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef State_h
#define State_h

#include <SFML/Graphics/Font.hpp>

class State {
public:
    sf::Font* font;
    
    virtual void init(int status) = 0;
    virtual void handle_input() = 0;
    virtual void update(float dt) = 0;
    virtual void draw (float dt) = 0;
    
    virtual void pause() = 0;
    virtual void resume() = 0;
    
    virtual ~State() {}
};

#endif /* State_h */
