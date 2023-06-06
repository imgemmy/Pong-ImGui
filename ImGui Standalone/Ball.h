#pragma once
#include "Math.h"
#include <stdlib.h>

struct BallComponent
{
	const int startingXPos = 390; //Starting position X
	const int radius = 5; //Radius of ball
	const float scaleVelocity = 1.1f; //The balls' scaling velocity each hit
	
	Vector2 direction = Vector2(.1,.1); //Balls direction / angle
	Vector2 velocity = Vector2(1, Math::RandomNumber(-1, 1)); //Velocity, self explanitory
	Vector2 position; //Position, velocity adds to this
};

enum BallState
{
	NoCollision = 0,
	BouncedOffWall = 1,
	BouncedOffPlayer = 2,
	BouncedOffBackBoard = 3,
	GameOver = 4
};

namespace BallController
{
	void BallMovement(BallComponent& Ball);
	int BallCollision(BallComponent& Ball, float playerPositionY);
	void BallPhysics(BallComponent& Ball);
}

extern BallComponent Ball;