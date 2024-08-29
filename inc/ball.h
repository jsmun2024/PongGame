#pragma once

class Ball
{
public:
    Ball();
    void Update();
    void Draw();
    float getY() const;
    float getX() const;
    float getRadius() const;
    int getSpeedX() const;
    int getSpeedY() const;
    void ReverseSpeedX();
    int getPlayerScore();
    int getCPUScore();
    void resetBall();
    void SpeedUpX();
    void SpeedUpY();

protected:
    float x;
    float y;
    int speedX;
    int speedY;
    int radius;
};