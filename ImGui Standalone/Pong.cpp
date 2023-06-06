#include "Pong.h"
#include "ImGui/imgui.h"
#include <iostream>


void Pong::Render(PlayerStruct &Player, BallComponent &Ball)
{
	//Get windowed at center pos for drawlist to be on window
	ImVec2 window_pos = ImGui::GetWindowPos();
	ImVec2 window_size = ImGui::GetWindowSize();
	ImVec2 window_center = ImVec2(window_pos.x + window_size.x * 0.5f, window_pos.y + window_size.y * 0.5f);

	//Player Movement
	PlayerController::PlayerMovement(Player);
	ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(window_center.x - Player.playerXPos, window_center.y + Player.playerHeight - Player.playerYPos), ImVec2(window_center.x - Player.playerXPos, window_center.y - Player.playerYPos), ImColor(255, 255, 255, 255), 5, 0);

	//Ball Movement
	BallController::BallMovement(Ball);
	ImGui::GetForegroundDrawList()->AddCircleFilled(ImVec2(window_center.x + Ball.position.x, window_center.y + Ball.position.y), Ball.radius, ImColor(255, 255, 255, 200), 15);

	//Draw Score
	ImGui::SetCursorPos(ImVec2(425, 50));
	ImGui::Text("Score: %d", Player.score);
}

void Pong::GameOverScreen()
{
	ImGui::BeginChild("##end-screen");
	{

		ImGui::SetCursorPos(ImVec2(415, 160));
		ImGui::Text("Game Over!");

		ImGui::SetCursorPos(ImVec2(350, 180));
		if (ImGui::Button("Play Again", ImVec2(200, 100)))
		{
			Player.isGameStart = true;
			Player.score = 0;
		}
	}
	ImGui::EndChild();


}