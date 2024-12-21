#include <iostream>
#include <raylib.h>
#include "game.h"
#include "colors.h"
//#pragma warning(disable:4996)

double lastUpdateTime = 0;

auto eventTrigger(double interval)->bool
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

auto main()->int 
{
	InitWindow(500, 620, "Tetris-Gonga");

	SetTargetFPS(60);
	Font font = LoadFontEx("Font/Grosball.otf", 64, 0, 0);

	Game game = Game();

	while (WindowShouldClose() == false)
	{
		UpdateMusicStream(game.music);
		game.HandleInput();

		if (eventTrigger(0.2))
			game.MoveBlockDown();

		BeginDrawing();
		ClearBackground(black);
		DrawTextEx(font, "Score", { 363, 15 }, 38, 2, altWhite);
		DrawTextEx(font, "Next", { 370, 175 }, 38, 2, altWhite);

		if (game.gameOver)  
            DrawTextEx(font, "GAME OVER", { 320, 450 }, 25, 2, WHITE), DrawTextEx(font, "PRESS ANY KEY", { 320, 470 }, 25, 2, WHITE); 
        
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);

		char scoreText[10];
		sprintf(scoreText, "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);


		DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
		game.Draw();


		EndDrawing();
	}

	CloseWindow();
}
