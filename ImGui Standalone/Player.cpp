#include "Player.h"
#include <Windows.h>
#include "Math.h"

//Initialize Player
PlayerStruct Player;

//Movement, note that ImGui is running at 60hz so we don't need a delta time.
void PlayerController::PlayerMovement(PlayerStruct& Player)
{
	//Key Press W/UP arrow
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(0x57))
	{
		Player.playerYPos += 1.5;
	}
	//Key Press S/DOWN arrow
	else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(0x53))
	{
		Player.playerYPos -= 1.5;
	}

	//Limit Range
	Player.playerYPos = Math::Range(Player.playerYPos, -190, 230);
}