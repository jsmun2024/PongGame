#include "player.h"
#include <raylib.h>

Player::Player()
{
    width = 25;
    height = 120;
    x = 1280 - width - 10;
    y = 800/2 - height/2;
    speed = 6;
}


void Player::Draw()
{
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
}

void Player :: LimitMovement()
{
    if (y <= 0)
    {
        y= 0;
    }
    if (y + height  >= 800)
    {
        y = 800 - height;
    }
}
void Player::Update()
{
    if (IsKeyDown(KEY_UP))
    {
        y = y - speed;
    }

    if (IsKeyDown(KEY_DOWN))
    {
        y = y + speed;
    }

    LimitMovement();
}

float Player::getX() const 
{
    return x;
}

float Player::getY() const 
{
    return y;
}
float Player::getWidth() const 
{
    return width;
}

float Player::getHeight() const 
{
    return height;
}
