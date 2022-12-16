//
//  River.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/River.hpp"

int River::get_maxlog(){
    int road_bd = (lev.lev() - 1) / 3 + 1;
    int car_left = 0;
    if (lev.lev() % 3 == 1) {
        if (lev.road_remain() <= 2) {
            return 4;
        }
    }
    car_left = lev.lev() - (road_bd - lev.road_remain()) * CAR_PER_LANE;
    return 6 - std::min(car_left, 3);
}


River::River(handler_ptr _tools, Level level, Position pos) : Lane(_tools, pos, level)
{
    Lane::change_image(tools->theme_controller.get("RIVER"));

    speed = rand() % (200 - 50 + 1) + 50;

    dir = rand() % 2;

    max_log = get_maxlog();

    river_sound.setBuffer(tools->theme_controller.get_buffer(river_sound_hash_name));

    spawn();
}

void River::stop() { 
    traffic_light = 1;
    for (auto& i : float_objs) i->stop();
}

void River::slowdown() {
    traffic_light = 2;

    for (auto& i : float_objs) i->slowndown();
}

void River::run() {
    traffic_light = 0;
    
    for (auto& i : float_objs) i->run(speed);
}

void River::spawn()
{
    int type_of_animal = rand() % 2;

    if (float_objs.size() == max_log + 3) return;

    else if (float_objs.size() == 0) {
        while (true) 
        {
            int index = rand() % 10;
            
            for (int i = 0; i < float_objs.size(); i++) 
            {
                if (index == float_objs[i]->position().get_x() / 100) {
                    
                    index = -1;

                    break;
                }
            }

            if (index > -1) {

                int size = float_objs.size() + 1;

                if (size <= 3) 
                {
                    int type = rand() % 2;

                    if (type == 0) 
                    {
                        Hippo* newHippo = new Hippo(tools, dir, Position(index * 100, Lane::position().get_y()), speed);
                        float_objs.push_back(newHippo);
                    }

                    else 
                    {
                        Croc* newCroc = new Croc(tools, dir, Position(index * 100, Lane::position().get_y()), speed);
                        float_objs.push_back(newCroc);
                    }
                }
                else
                {
                    Log* newLog = new Log(tools, dir, Position(index * 100, Lane::position().get_y() + 25), speed);
                    float_objs.push_back(newLog);
                }

            }
            
            if (float_objs.size() == max_log + 3)
            {
                sort(float_objs.begin(), float_objs.end(), [&](floatObject* a, floatObject* b)
                {
                    return ((!dir) ? (a->position().get_x() < b->position().get_x()) : (a->position().get_x() > b->position().get_x()));
                });
                
                break;
            }

        }
    }

    else
    {
        int cnt_log = 0;

        for (auto& each : float_objs) {
            if (each->get_type() == 2) {
                cnt_log++;
            }
        }

        if (cnt_log == max_log) 
        {
            int type_of_animal = rand() % 2;

            if (type_of_animal) 
            {
                Croc* newCroc = new Croc(tools, dir, Position((!dir) ? 1000 : -100, Lane::position().get_y()), speed);
                float_objs.push_back(newCroc);
            }

            else {
                Hippo * newHippo = new Hippo(tools, dir, Position((!dir) ? 1000 : -100, Lane::position().get_y()), speed);
                float_objs.push_back(newHippo);
            }
        }

        else 
        {
            Log* newLog = new Log(tools, dir, Position((!dir) ? 1000 : -100, Lane::position().get_y() + 25), speed);
            float_objs.push_back(newLog);
        }
    }

}

River::~River() {
    while (!float_objs.empty())
    {
        if (float_objs[0])
        {
            delete float_objs[0];
            float_objs[0] = nullptr;
        }
        float_objs.erase(float_objs.begin());
    }
}

void River::adjust_objects()
{
    
    Lane::adjust_objects();
    
    for (int i = 0; i < float_objs.size(); i++)
    {
        
        auto each = float_objs[i];
        
        if (each->get_type() == 2) each->locate_at(each->position().get_x(), position().get_y());
        
        else if (each->get_type() == 1) each->locate_at(each->position().get_x(), position().get_y() + 30);
        
        else each->locate_at(each->position().get_x(), position().get_y() + 10);
        
        if (dir) each->move_right();
        
        else each->move_left();
        
        each->adjust_objects();
        
        if (each->position().out_of_screen(0))
        {
            delete float_objs[i];
            float_objs[i] = nullptr;
            float_objs.erase(float_objs.begin() + i);
        }
    }
    spawn();
}

void River::draw()
{
    Lane::draw();
    
    for (auto& each: float_objs)
    {
        if (traffic_light != 1 || !each->is_animal()) each->draw();
    }
}

bool River::check_lost() {
    Position people_pos = people_position(), fpos;
    bool direction = dir;
    
    for (int i = 0; i < float_objs.size(); i++) {

        fpos = float_objs[i]->position();
        if ((float_objs[i]->get_type() == 2 && people_pos.get_x() >= fpos.get_x() - people_size && people_pos.get_x() <= fpos.get_x() + dsize + 2) || traffic_light == 1) /* the function returns false, which means you are lost, if people is not standing on the log when the traffic light is not red.*/
            return false;

        if (float_objs[i]->get_type() != 2 && people_pos.get_x() >= fpos.get_x() - people_size && people_pos.get_x() <= fpos.get_x() + dsize + 2) /*on the other hand, it returns true*/ {

            if (traffic_light != 1) //animal sound

                float_objs[i]->tell();

            else river_sound.play(); // river sound

            return true;
        }

    }

    river_sound.play();

    return true;
}

void River::set_current(People*& mario, int type)
{
    int j=0;
    /*if (!is_current())
    {
        Lane::set_current(mario);
        
        Position mariop = Position(mario->get_position().x, Lane::position().get_y());
        
        bool check = false;
        
        for (int i = 0; i < float_objs.size(); i++)
        {
            if (float_objs[i]->get_type() == 2)
            {
                
                Position obj_p = float_objs[i]->position();
                
                
                if (mariop.inRect(obj_p))
                {
                    float_objs[i]->setCurrent(mario);
                    
                    check = true;
                    
                    break;
                }
            }
            
        }
        
        if (check == false)
        {
            check_lost();
        }
    }
    else
    {*/
    
    
    int currentLog = get_currentlog(); //if people is standing on any log, return the log index. Otherwise, return -1.
    Position mariop = Position(mario->get_position().x, Lane::position().get_y()); // current position of mario
    
    j = mariop.get_x()/100; //finding the cell that people is standing on the river.
    
    int movObj = (type == 2) ? get_prevobj(j) : get_nextobj(j); //if move right (type == 1), searching for the right cell on the river. On the contrary, searching for the cell on the left handside.
    
    if (currentLog != -1) float_objs[currentLog]->unset();
    
    //lane set mario.
    Lane::unset();
    Lane::set_current(mario, type);
    
    if (check_lost()) return;
    for (int i = 0; i < float_objs.size(); i++)
    {
        Position obj_p = float_objs[i]->position();
        if (mariop.inRect(obj_p)) //if people is located inside the cell
        {
            float_objs[i]->setCurrent(mario);
            if (float_objs[i]->get_type() == 2)/*if log...*/{
                float_objs[i]->adjust_objects(); //set people to the center of log.
            }
            break;
        }
    }
    mario->stop_moving(); //change the moving attribute inside people class to false, meaning people is not move, in order to let adjust_object in the log class working to update the position of people following the log if standing on the log
    
    
        /*a
        int currentPos = float_objs[j]->position().get_x();
        int movPos = float_objs[movObj]->position().get_x();
        f (abs(movPos - currentPos) > 101) {
         check_lost();
         }*/
    //}

}


void River::save(std::ofstream& fout) {
    fout << type() << " " << level() << " " << lev.path_remain() << " " << lev.road_remain() << std::endl;

    fout << Lane::position().get_x() << " " << Lane::position().get_y() << std::endl;

    fout << is_current() << std::endl;

    fout << dir << " " << max_log << std::endl;

    fout << speed << std::endl;

    fout << is_current() << std::endl;

    for (auto& i : float_objs) i->save(fout);
}

int River::get_currentlog() {
    for (int i = 0; i < float_objs.size(); i++) {
        if (float_objs[i]->isCurrent()) {
            return i;
        }
    }
    return -1;
}

int River::get_nextobj(int current_log_index)
{
    return current_log_index + 1;
}

int River::get_prevobj(int current_log_index)
{
    return current_log_index - 1;
}


void River::unset() {
    Lane::unset();
    int current_index = get_currentlog();
    if (current_index == -1) return;
    float_objs[current_index]->unset();
}

void River::loading(std::ifstream& fin) {
    
}
