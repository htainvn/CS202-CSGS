#ifndef People_hpp
#define People_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "src/definition_library.hpp"
//#include "src/LaneGenerator.hpp"


class People
{
private:
    sf::Sprite sp;
    bool alive_;
    std::string type_;
    int index = 0;
public:
    
    int set_current_lane(int index);
    
    People() {}
    People(ResourceManager& resource_manager, bool alive = true, std::string type = "MARIO_FORWARD");
    ~People();
    std::string type_path () const;
    sf::Vector2f get_position() const;
    bool can_move_right();
    bool can_move_left();
    bool can_move_down();
    bool can_move_forward();
    void move_right(ResourceManager& resource_manager);
    void move_left(ResourceManager& resource_manager);
    void move_down(ResourceManager& resource_manager);
    void move_forward(/*sf::Vector2f vec,*/ ResourceManager& resource_manager);
    void change_type (std::string type);
    void scroll();
    bool touch_border();
    void go_to_position(int x, int y);
    void move (sf::Vector2f vec);
    bool is_alive();
    bool is_mid_height();
    int lane() const;
    sf::Sprite& get_sprite ();
};

sf::Sprite set_character (const People &character);

bool is_collision(sf::Vector2f obs, sf::Vector2f character);

#endif /* People_hpp  */
