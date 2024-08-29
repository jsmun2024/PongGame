#pragma once

class Player
{
    public:
    Player();
    void Draw();
    void Update();
    float getY() const;
    float getX() const;
    float getWidth() const;
    float getHeight() const;

    protected:
    float x,y;
    float width, height;
    int speed;
    void LimitMovement();
};