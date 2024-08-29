#include "cpu.h"
#include "player.h"
#include "ball.h"
#include <raylib.h>

CPUPaddle::CPUPaddle()
{
    width = 25;
    height = 120;
    x = 10;
    y = 800/2 - height/2;
    speed = 6;
}

void CPUPaddle::Update(int ball_y)
{
    //If Ball At a Higher Height than the Center of the Paddle, Move Up
    if(y + height/2 > ball_y)
    {
        y = y - speed;
    }
    
    if (y+height/2 < ball_y)
    {
        y = y + speed;
    }


    //Inherited Method
    LimitMovement();
}