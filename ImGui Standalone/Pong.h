#pragma once
#include "Player.h"
#include "Ball.h"

namespace Pong
{
	void Render(PlayerStruct& Player, BallComponent& Ball);
	void GameOverScreen();
}
