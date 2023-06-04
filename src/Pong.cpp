#include <SDL2/SDL.h>
#include "headers/Pong.hpp"
#include "headers/config.hpp"
#include "headers/Utils.hpp"


Pong::Pong() : 
m_window(nullptr), 
m_renderer(nullptr), 
m_running(false), 
m_screenWidth(SCREEN_WIDTH), 
m_screenHeight(SCREEN_HEIGHT) 
{}

Pong::~Pong(){
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Pong::init(){
if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return;
    }

    m_window = SDL_CreateWindow(
            "Pong", 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, 
            SCREEN_WIDTH, 
            SCREEN_HEIGHT, 
            0
        );

    if (!m_window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!m_renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create renderer: %s", SDL_GetError());
        return;
    }

    run();
}


void Pong::run(){
    m_running = true;
    while (m_running) {
        while (SDL_PollEvent(&m_event) > 0) {
            m_playerPaddle.handle_events(m_event);
            switch(m_event.type){
                case SDL_QUIT:
                    m_running = false;
                    break;
            }
        }
        
        update(DELTA_TIME);
        render();
    }
}

void Pong::update(double delta_time) {
    Direction ball_direction = m_ball.get_direction();
    m_ball.update(delta_time, ball_direction, m_playerPaddle, m_CPUPaddle);
    m_playerPaddle.update(delta_time);
    m_CPUPaddle.update(delta_time, m_ball.get_position_y());
    
}

void Pong::render() {
    SDL_RenderClear(m_renderer);

    m_playerPaddle.draw(m_renderer);
    m_CPUPaddle.draw(m_renderer);
    drawObject(m_renderer, m_ball.get_body());

    SDL_RenderPresent(m_renderer);
}
