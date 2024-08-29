#pragma once
#include "player.h"
#include "ball.h"

//Inheritance to obtain Methods and Attributes
class CPUPaddle: public Player
{

public:
    CPUPaddle();
    void Update(int ball_y);
};