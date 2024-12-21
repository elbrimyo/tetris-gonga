#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game 
{
public:
	Game();
	~Game();
	void Draw();
	void HandleInput();
	void MoveBlockDown();
	bool gameOver;
	int score;
	Music music;

private:
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	bool BlockFits();
	bool isBlockOutside();
	void MoveBlockLeft();
	void MoveBlockRight();
	void RotateBlock();
	void LockBlock();
	void Reset();
	void updateScore(int linesCleared, int moveDownPoints);
	std::vector<Block> blocks;
	Grid grid;
	Block currentBlock;
	Block nextBlock;
	Sound rotateSound;
	Sound clearSound;
};