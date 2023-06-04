#ifndef PONG_H
#define PONG_H

#include <SDL2/SDL.h>
#include "PlayerPaddle.hpp"
#include "CPUPaddle.hpp"
#include "Ball.hpp"

class Pong {
    public:
        Pong();
        ~Pong();

        void init();
        void run();
        void update(double delta_time);
        void render();

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        SDL_Event   m_event;

        PlayerPaddle m_playerPaddle;
        CPUPaddle m_CPUPaddle;

        Ball m_ball;
        
        bool m_running;
        int m_screenWidth;
        int m_screenHeight;
};

#endif