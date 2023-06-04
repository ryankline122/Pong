#include <SDL2/SDL.h>
#include "headers/CPUPaddle.hpp"
#include "headers/config.hpp"

CPUPaddle::CPUPaddle(){

    m_position_x = CPU_PADDLE_START_X;
    m_position_y = CPU_PADDLE_START_Y;

    m_paddle.x = m_position_x;
    m_paddle.y = m_position_y;
    m_paddle.h = PADDLE_HEIGHT;
    m_paddle.w = PADDLE_WIDTH;

    m_direction = Direction::NONE;
    m_movement_speed = PADDLE_SPEED;

};


void CPUPaddle::update(double delta_time, int ball_position_y) {
    /*
        Updates the current frame
    */

    // Calculate the distance between the center of the paddle and the center of the ball
    int distance = ball_position_y - (m_position_y + m_paddle.h/2);

    // Move the paddle up or down based on the distance from the ball
    if (distance > 0 && m_position_y < SCREEN_HEIGHT - m_paddle.h) {
        m_position_y += m_movement_speed * delta_time;
    }
    else if (distance < 0 && m_position_y > 0) {
        m_position_y -= m_movement_speed * delta_time;
    }

    m_paddle.x = m_position_x;
    m_paddle.y = m_position_y;
}


void CPUPaddle::draw(SDL_Renderer *renderer){
    /*
        Draws new frame to the renderer
    */

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &m_paddle);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

SDL_Rect CPUPaddle::get_body(){
    return m_paddle;
}