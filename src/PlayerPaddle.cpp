#include <SDL2/SDL.h>
#include "headers/PlayerPaddle.hpp"
#include "headers/config.hpp"

PlayerPaddle::PlayerPaddle(){

    m_paddle.x = 0;
    m_paddle.y = 0;
    m_paddle.h = PADDLE_HEIGHT;
    m_paddle.w = PADDLE_WIDTH;

    m_position_x = PLAYER_PADDLE_START_X;
    m_position_y = PLAYER_PADDLE_START_Y;

    m_direction = Direction::NONE;
    m_movement_speed = PADDLE_SPEED;

};


void PlayerPaddle::handle_events(SDL_Event const &event){
    /*

        Handles Keyboard input. Player should be able to move up and down.
        If no keys pressed, player should not move.
    
    */

    switch(event.type){
        case SDL_KEYDOWN:{
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(keys[SDL_SCANCODE_W] == 1)
                m_direction = Direction::UP;
            else if(keys[SDL_SCANCODE_S] == 1)
                m_direction = Direction::DOWN;
            break;
        }

        case SDL_KEYUP:
            m_direction = Direction::NONE;
            break;
    }

}


void PlayerPaddle::update(double delta_time){
    /*
    
        Updates the current frame

    */

    if(m_direction == Direction::UP){
        if(m_position_y > 0)
            m_position_y -= m_movement_speed * delta_time;
    }else if(m_direction == Direction::DOWN){
        if(m_position_y < SCREEN_HEIGHT - m_paddle.h)
            m_position_y += m_movement_speed * delta_time;
    }else{
        m_position_y += 0.0;
    }

    m_paddle.x = m_position_x;
    m_paddle.y = m_position_y;

}


void PlayerPaddle::draw(SDL_Renderer *renderer){
    /*
        Draws new frame to the renderer
    */

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &m_paddle);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}


SDL_Rect PlayerPaddle::get_body(){
    return m_paddle;
}