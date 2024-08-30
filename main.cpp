#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "player.h"
#include "cpu.h"

using namespace std;

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};


//Creating an Instance of the Ball (As Header is already included)
Ball ball;
Player paddle1;
CPUPaddle CPU;

int main()
{
    cout << "Starting the game" << endl;

    // Creating the Blank Screen (General Game Settings)
    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow (screen_width, screen_height, "Mun Pong!");
    SetTargetFPS(50);

    const int winningScore = 1;  // Set the winning score threshold
    bool gameOver = false;       // Flag to check if the game is over

    //Main Game Loop

    //Check if ESC Key on Keyboard is pressed or 
    //Close Icon on Window is Pressed (Close the Game)
    //Returns true, game loop ends and window is deleted
    while(WindowShouldClose() == false)
    {
        if (!gameOver)
        {
            // Create a canvas/area to draw the game objects
            BeginDrawing();

            // Updating The Game Components
            ball.Update();
            paddle1.Update();
            CPU.Update(ball.getY());

            // Collision Check
            if (CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getRadius(), Rectangle{paddle1.getX(), paddle1.getY(), paddle1.getWidth(), paddle1.getHeight()}))
            {
                ball.ReverseSpeedX();
                ball.SpeedUpX();
                ball.SpeedUpY();
            }

            if (CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getRadius(), Rectangle{CPU.getX(), CPU.getY(), CPU.getWidth(), CPU.getHeight()}))
            {
                ball.ReverseSpeedX();
                ball.SpeedUpX();
                ball.SpeedUpY();
            }

            // Check if either player or CPU has reached the winning score
            if (ball.getCPUScore() >= winningScore || ball.getPlayerScore() >= winningScore)
            {
                gameOver = true; // Set the game over flag to true
            }

            // Drawing the Actual Objects
            ClearBackground(Dark_Green);
            DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
            DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
            DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);

            ball.Draw();
            paddle1.Draw();
            CPU.Draw();

            DrawText(TextFormat("%i", ball.getCPUScore()), screen_width / 4 - 20, 20, 80, WHITE);
            DrawText(TextFormat("%i", ball.getPlayerScore()), 3 * screen_width / 4 - 20, 20, 80, WHITE);

            // Ends the drawings
            EndDrawing();
        }
        else
        { 
            // Draw game over screen
            BeginDrawing();
            ClearBackground(Dark_Green);
            DrawText("Game Over", screen_width / 2 - 200, screen_height / 2 - 80, 80, WHITE);
            DrawText(TextFormat("Final Score - Player: %i | CPU: %i", ball.getPlayerScore(), ball.getCPUScore()), screen_width / 2 - 300, screen_height / 2 + 20, 40, WHITE);
            DrawText("Press Escape to Exit", screen_width / 2 - 210, screen_height / 2 + 100, 40, WHITE);
            EndDrawing();

            // Wait for the user to press ENTER to close the window
            if (IsKeyPressed(KEY_ESCAPE))
            {
                break;
            }
        }
    }

    // Close the Window
    CloseWindow();

    return 0;
}