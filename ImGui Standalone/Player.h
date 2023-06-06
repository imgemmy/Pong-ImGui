#pragma once

struct PlayerStruct
{
	const float playerXPos = 400;
	const int playerHeight = 60;
	float playerYPos;
	int score = 0;
	bool isGameStart = true;
};

namespace PlayerController
{
	void PlayerMovement(PlayerStruct& Player);
}


extern PlayerStruct Player;
