#include "People.hpp"

People::People(handler_ptr _tools, bool alive, std::string type) : tools(_tools)
{
    sp.setTexture(_tools->theme_controller.get(type));
    sp.setPosition(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT - 300 + 20));
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
    if (v.x + 2*people_size >= SCREEN_WIDTH || alive_ == false)
        return false;
    else
        return true;
}

bool People::can_move_left(){
    sf::Vector2f v = sp.getPosition();
    if (v.x - people_size <= 0 || alive_ == false)
        return false;
    else
        return true;
}

bool People::can_move_forward(){
    sf::Vector2f v = sp.getPosition();
    if (v.y > 100 && alive_ == true)
        return true;
    return false;
}

bool People::can_move_down(){
    sf::Vector2f v = sp.getPosition();
    if (v.y + 100 < SCREEN_HEIGHT && alive_ == true)
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

void People::move_right(int type){
    land_type = type;
    sf::Vector2f v = sp.getPosition();
    if (can_move_right() || type == 3)
    {
        sf::Vector2f v = sp.getPosition();
        sp.move(sf::Vector2f(0.5, 0));
        type_movement = 1;
        cnt_movement--;
        
        if (!cnt_movement) type_ = "MARIO_RIGHT";
        if (1 <= cnt_movement && cnt_movement <= 100) type_ = "MARIO_RIGHTRUN";
        if (101 <= cnt_movement && cnt_movement <= 199) type_ = "MARIO_RIGHTGO";

        sp.setTexture(tools->theme_controller.get(type_));
    }
}

void People::move_left(int type){
    land_type = type;
    sf::Vector2f v = sp.getPosition();
    if (can_move_left() || type == 3)
    {
        sf::Vector2f v = sp.getPosition();
        sp.move(sf::Vector2f(-0.5, 0));
        type_movement = 2;
        cnt_movement--;
        if (!cnt_movement) type_ = "MARIO_LEFT";
        if (1 <= cnt_movement && cnt_movement <= 100) type_ = "MARIO_LEFTRUN";
        if (101 <= cnt_movement && cnt_movement <= 199) type_ = "MARIO_LEFTGO";

        sp.setTexture(tools->theme_controller.get(type_));
    }
}

void People::move_down(){
    sf::Vector2f v = sp.getPosition();
    if (can_move_forward())
    {
        sf::Vector2f v = sp.getPosition();
        sp.move(sf::Vector2f(0, 0.5));
        type_movement = 3;
        cnt_movement--;
        if (!cnt_movement) type_ = "MARIO_DOWNWARD";
        if (1 <= cnt_movement && cnt_movement <= 100) type_ = "MARIO_DOWNWARDGO";
        if (101 <= cnt_movement && cnt_movement <= 199) type_ = "MARIO_DOWNWARDGO";

        sp.setTexture(tools->theme_controller.get(type_));
    }
}

int People::lane() const{
    return 0;
}

void People::move_forward(/*sf::Vector2f vec,*/){
    sf::Vector2f v = sp.getPosition();
    if (can_move_down())
    {
        sf::Vector2f v = sp.getPosition();
        sp.move(sf::Vector2f(0, -0.5));
        type_movement = 0;
        cnt_movement--;
        if (!cnt_movement) type_ = "MARIO_FORWARD";
        if (1 <= cnt_movement && cnt_movement <= 100) type_ = "MARIO_FORWARDRUN";
        if (101 <= cnt_movement && cnt_movement <= 199) type_ = "MARIO_FORWARDGO";

        sp.setTexture(tools->theme_controller.get(type_));
    }
}

bool People::touch_border() {
    sf::Vector2f v = get_position();
    if (v.y + 5 >= SCREEN_HEIGHT || v.x < 0 || v.x + people_size > SCREEN_WIDTH)
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
    return 0;
}

void People::lost() {
    if(is_alive())
        alive_ = false;
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

void People::moving(){
    isMoving = true;
}

void People::stop_moving(){
    isMoving = false;
}

bool People::is_moving(){
    return isMoving;
}

void People::loading(std::ifstream& fin)
{
    float positionx, positiony;
    fin >> type_ >> positionx >> positiony;
    go_to_position(positionx, positiony);
    fin >> alive_ >> isMoving >> cnt_movement >> type_movement;
}

void People::start_movement(int type_) {
    cnt_movement = 200;
}

int People::update()
{
    if (cnt_movement)
    {
        switch(type_movement) {
            case 0:
            {
                move_forward();
            }
            break;
            case 1:
            {
                move_right(land_type);
            }
            break;
            case 2:
            {
                move_left(land_type);
            }
            break;
            case 3:
            {
                move_down();
            }
            break;
        }
        return -1;
    }
    else
    {
        int tmp = type_movement;
        type_movement = -1;
        return tmp;
    }
    
}

Position People::getSize() {
    return Position(sp.getTexture()->getSize().x, sp.getTexture()->getSize().y);
}

void People::save(std::ofstream& fout) {
    fout << type_ << "\n";
    fout << get_position().x << " " << get_position().y << "\n";
    fout << alive_ << " " << isMoving << " " << cnt_movement << " " << type_movement << "\n";
}
