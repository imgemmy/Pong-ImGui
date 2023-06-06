#include "Ball.h"
#include "Player.h"
#include "Pong.h"
#include <iostream>
#include <cmath>

BallComponent Ball;
bool flipVelocity = false;


int BallController::BallCollision(BallComponent& Ball, float playerPositionY)
{
   
    if (Ball.position.x <= -395 && Ball.position.x >= -400)
    {
        if (-Ball.position.y >= Player.playerYPos - 60 && -Ball.position.y <= Player.playerYPos)
        {
            Player.score++;
            return BallState::BouncedOffPlayer; //Ball hitting player
        }
    }
    else if (Ball.position.x >= 450)
        return BallState::BouncedOffBackBoard; //Ball hitting backboard

    else if (Ball.position.y >= 240 || Ball.position.y <= -220)
        return BallState::BouncedOffWall; //Ball hitting ceiling/floor

    else if (Ball.position.x <= -410)
        return BallState::GameOver; //Went over player, therefore game over

    else
        return BallState::NoCollision; //No hit

}

void BallController::BallPhysics(BallComponent& Ball)
{
    
    if (BallController::BallCollision(Ball, Player.playerYPos) == BallState::BouncedOffPlayer)
    {
        //If there is a collision with a player added scale factor.
        //All other hits we don't want to add to velocity
        Ball.velocity.x = -Ball.velocity.x * Ball.scaleVelocity;
        
    }
    else if (BallController::BallCollision(Ball, Player.playerYPos) == BallState::BouncedOffBackBoard)
    {
        Ball.velocity.x = -Ball.velocity.x;
    }
    else if (BallController::BallCollision(Ball, Player.playerYPos) == BallState::BouncedOffWall)
    {
        Ball.velocity.y = -Ball.velocity.y;
    }
    else if (BallController::BallCollision(Ball, Player.playerYPos) == BallState::GameOver)
    {
        Pong::GameOverScreen();
    }

    //Add velocity to ball position every frame
    Ball.position.x -= Ball.velocity.x;
    Ball.position.y -= Ball.velocity.y;


}


void BallController::BallMovement(BallComponent& Ball)
{
    // Only set the ball to the starting position on game start
    if (Player.isGameStart)
    {
        Ball.position.x = Ball.startingXPos;
        Ball.position.y = 0;
        Ball.velocity = Vector2(1, Math::RandomNumber(-1, 1));
        Player.isGameStart = false;
    }

    BallController::BallPhysics(Ball); // Set the ball's angle based on the desired angle

}
