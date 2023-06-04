#include <SDL2/SDL.h>
#include "headers/Ball.hpp"
#include "headers/PlayerPaddle.hpp"
#include "headers/CPUPaddle.hpp"
#include "headers/config.hpp"
#include "headers/Utils.hpp"
#include <iostream>

Ball::Ball(){

    m_ball_position_x = BALL_START_X;
    m_ball_position_y = BALL_START_Y;

    m_body.x = m_ball_position_x;
    m_body.y = m_ball_position_y;
    m_body.w = BALL_WIDTH;
    m_body.h = BALL_HEIGHT;

    m_speed = BALL_SPEED;

    m_direction = Direction::LEFT;

    m_velocity_x = BALL_SPEED;
    m_velocity_y = 0;
    
}

void Ball::update(double delta_time, Direction direction, PlayerPaddle player, CPUPaddle cpu){
    /*
    
        Updates the current frame

    */
    m_direction = direction;

    // Update position based on velocity
    m_ball_position_x += m_velocity_x * delta_time;
    m_ball_position_y += m_velocity_y * delta_time;

    // Check for collisions with walls
    if(m_ball_position_x < 0){
        // Player 2 scores
        return;
    }else if(m_ball_position_x > SCREEN_WIDTH - m_body.w){
        // Player 1 scores
        return;
    }

    if(m_ball_position_y < 0 || m_ball_position_y > SCREEN_HEIGHT - m_body.h){
        // Bounce off top/bottom walls
        m_velocity_y = -m_velocity_y;
    }

    // Check for collision with paddles
    if((isColliding(m_body, player.get_body()) || isColliding(m_body, cpu.get_body()))){
        std::cout << "Increasing Speed!\n";
        increase_speed();
        std::cout << m_speed << "\n";

    }


    // Check for collision with paddles
    if((isColliding(m_body, player.get_body()))){
        // Bounce off left paddle
        m_velocity_x = m_speed;
        int bounce_up = generate_random_int(0, 1); 

        // TODO: Properly calculate velocities
        if(bounce_up == 0){
            m_velocity_y = 150;
        }else{
            m_velocity_y = -50;
        }

    }else if((isColliding(m_body, cpu.get_body()))){
        // Bounce off right paddle
        m_velocity_x = -m_speed;
        int bounce_up = generate_random_int(0, 1); 


        // TODO: Properly calculate velocities
        if(bounce_up == 0){
            m_velocity_y = 150;
        }else{
            m_velocity_y = -50;
        }
    }
    m_body.x = m_ball_position_x + (m_velocity_x * delta_time);
    m_body.y = m_ball_position_y + (m_velocity_y * delta_time);
}

void Ball::increase_speed(){
    if(m_speed < BALL_MAX_SPEED){
        m_speed += BALL_SPEED_MODIFIER;
    } 
}

int Ball::get_position_x(){
    return m_ball_position_x;
}

int Ball::get_position_y(){
    return m_ball_position_y; 
}

SDL_Rect Ball::get_body(){
    return m_body;
}

Direction Ball::get_direction(){
    return m_direction;
}
