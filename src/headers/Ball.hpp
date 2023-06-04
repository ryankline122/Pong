#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include "Utils.hpp"
#include "PlayerPaddle.hpp"
#include "CPUPaddle.hpp"


class Ball{

    public:

        Ball();
        ~Ball() = default;

        void update(double delta_time, Direction direction, PlayerPaddle player, CPUPaddle cpu);
        SDL_Rect get_body();
        Direction get_direction();
        int get_position_x();
        int get_position_y(); 
        double calculate_bounce_velocity(PlayerPaddle paddle);
        void increase_speed(); 

    private:

        SDL_Rect m_body;
        Direction m_direction;
        
        int m_ball_position_x;
        int m_ball_position_y;

        float m_speed;
        float m_velocity_x;
        float m_velocity_y;

};


#endif