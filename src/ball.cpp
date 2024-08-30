#include "ball.h"
#include <raylib.h>


int player_Score;
int CPU_Score;

Ball::Ball()
{
    x = 1280/2;
    y = 800/2;
    speedX = 6;
    speedY = 6;
    radius = 20;
}


//Ball Update Algorithm
void Ball::Update()
{
    x += speedX;
    y += speedY;

    if (x + radius >= GetScreenWidth())
    {
        CPU_Score++;
        resetBall();
    } 
    
    if(x - radius <= 0)
    {
        player_Score++;
        resetBall();    
    }

    if (y + radius >= GetScreenHeight() || y - radius <= 0)
        speedY *= -1;
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, WHITE);
}

float Ball::getX() const 
{
    return x;
}

float Ball::getY() const 
{
    return y;
}

float Ball::getRadius() const 
{
    return radius;
}

int Ball::getSpeedX() const 
{
    return speedX;
}

int Ball::getSpeedY() const 
{
    return speedY;
}

void Ball::ReverseSpeedX()
{
    speedX *= -1;
}

void Ball::SpeedUpX()
{
    speedX += 1;
}

void Ball::SpeedUpY()
{
    speedY += 1;
}

int Ball::getPlayerScore()
{
    return player_Score;
}

int Ball::getCPUScore()
{
    return CPU_Score;
}

void Ball::resetBall()
{
    for (int i = 0; i < 100; i++)
    {
        x = GetScreenWidth()/2;
        y = GetScreenHeight()/2;
    }

    //creating a list of two values
    int speed_Choice[2] = {-1, 1};
    speedX = 8*speed_Choice[GetRandomValue(0,1)];
    speedY = 8*speed_Choice[GetRandomValue(0,1)];
}
