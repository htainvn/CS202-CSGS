#include "People.hpp"

People::People(handler_ptr _tools, bool alive, std::string type) : tools(_tools)
{
    sp.setTexture(_tools->theme_controller.get(type));
    sp.setPosition(sf::Vector2f(SCREEN_WIDTH/2 + 25, SCREEN_HEIGHT - 300 + 20));
    alive_ = alive;
    type_ = type;
}

People::~People(){}

std::string People::type_path () const{
    return type_;
}

void People::go_to_position(float x, float y){
    sp.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f People::get_position() const{
    return sp.getPosition();
}

bool People::can_move_right(){
    sf::Vector2f v = sp.getPosition();
    if (v.x + dsize >= SCREEN_WIDTH)
        return false;
    else
        return true;
}

bool People::can_move_left(){
    sf::Vector2f v = sp.getPosition();
    if (v.x <= 25)
        return false;
    else
        return true;
}

bool People::can_move_forward(){
    sf::Vector2f v = sp.getPosition();
    if (v.y > 100)
        return true;
    return false;
}

bool People::can_move_down(){
    sf::Vector2f v = sp.getPosition();
    if (v.y + 100 < SCREEN_HEIGHT)
        return true;
    else
        return false;
}

bool People::is_mid_height(){
    sf::Vector2f v = sp.getPosition();
    if (v.y <= SCREEN_HEIGHT - 300)
        return true;
    return false;
}

void People::move_right(){
    sf::Vector2f v = sp.getPosition();
    if (can_move_right())
    {
        sp.setPosition(sf::Vector2f(v.x + 100, v.y));
        type_ = "MARIO_RIGHT";
        sp.setTexture(tools->theme_controller.get(type_));
    }
}
void People::move_left(){
    sf::Vector2f v = sp.getPosition();
    if (can_move_left())
    {
        sp.setPosition(sf::Vector2f(v.x - 100, v.y));
        type_ = "MARIO_LEFT";
        sp.setTexture(tools->theme_controller.get(type_));
    }
}

void People::move_down(){
    if (can_move_down())
    {
        index--;
        type_ = "MARIO_DOWNWARD";
        sp.setTexture(tools->theme_controller.get(type_));
    }
}

int People::lane() const{
    return index;
}

void People::move_forward(/*sf::Vector2f vec,*/){
    if(can_move_forward()){
        index++;
        type_ = "MARIO_FORWARD";
        sp.setTexture(tools->theme_controller.get(type_));
    }
}

bool People::touch_border() {
    sf::Vector2f v = get_position();
    if (v.y + 60 >= SCREEN_HEIGHT || v.x < 0 || v.x + 40 > SCREEN_WIDTH)
    {
        alive_ = false;
        return true;
    }
    return false;
}

bool People::is_alive(){
    return alive_;
}

void People::change_type (std::string type){
    type_ = type;
}

sf::Sprite& People::get_sprite () {
    return sp;
}

void People::move (sf::Vector2f vec){
    sp.move(vec);
}

int People::set_current_lane(int _index) {
    index = _index;
    return 0;
}


sf::Sprite set_character(const People &character){
    sf::Sprite sp;
    sf::Texture image;
    if (!image.loadFromFile(character.type_path()))
    {
        std::cout << "image loading error!" << std::endl;
    }
    sp.setTexture(image);
    sf::Vector2f v = character.get_position();
    sp.setPosition(v);
    return sp;
}

bool is_collision(sf::Vector2f vector, sf::Vector2f character){
    if (vector.x >= character.x && vector.x <= character.x + 100 && vector.y == character.y)
    {
        return true;
    }
    return false;
}
