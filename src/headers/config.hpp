#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <random>

// ******* Window *******

float const DELTA_TIME = 1.0/60.0;
float const SCREEN_WIDTH = 800;
float const SCREEN_HEIGHT = 600;


// ******* Paddles *******

int const PADDLE_HEIGHT = 100;
int const PADDLE_WIDTH = 20;

float const PADDLE_SPEED = 300.0;

float const PLAYER_PADDLE_START_X = 10.0;
float const PLAYER_PADDLE_START_Y = SCREEN_HEIGHT/2;

float const CPU_PADDLE_START_X = 770.0;
float const CPU_PADDLE_START_Y = SCREEN_HEIGHT/2;


// ******* Ball *******

int const BALL_HEIGHT = 16;
int const BALL_WIDTH = 16;

float const BALL_SPEED = 200.0;
float const BALL_SPEED_MODIFIER = 20;
float const BALL_MAX_SPEED = 1500;

float const BALL_START_X = SCREEN_WIDTH/2;
float const BALL_START_Y = SCREEN_HEIGHT/2;



#endif
