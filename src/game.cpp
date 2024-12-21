#include "game.h"
#include <random>

Game::Game()
{
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameOver = false;
	score = 0;
	InitAudioDevice();
	music = LoadMusicStream("Sounds/music.mp3");
	PlayMusicStream(music);
	rotateSound = LoadSound("Sounds/rotate.mp3");
	clearSound = LoadSound("Sounds/clear.mp3");
}

Game::~Game()
{
	UnloadSound(rotateSound);
	UnloadSound(clearSound);
	UnloadMusicStream(music);
	CloseAudioDevice();
}

auto Game::GetRandomBlock() -> Block 
{
	if (blocks.empty())
		blocks = GetAllBlocks();
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}


auto Game::GetAllBlocks() -> std::vector<Block> 
{
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::Draw() 
{
	grid.Draw();
	currentBlock.Draw(11, 11);

	switch (nextBlock.id)
	{
	case 3:
		nextBlock.Draw(255, 290);
		break;
	case 4:
		nextBlock.Draw(255, 280);
		break;
	default:
		nextBlock.Draw(270, 270);
		break;
	}
}

void Game::HandleInput() 
{
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0)
	{
		gameOver = false;
		Reset();
	}

	switch (keyPressed) 
    {
	case KEY_LEFT:
		MoveBlockLeft(); break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		updateScore(0, 1);
		break;
	case KEY_UP:
		RotateBlock();
		break;
	}
}

void Game::MoveBlockLeft() 
{
	if (!gameOver) {
		currentBlock.Move(0, -1);
		if (isBlockOutside() || BlockFits() == false)
			currentBlock.Move(0, 1);
	}
}

void Game::MoveBlockRight() 
{
	if (!gameOver) {
		currentBlock.Move(0, 1);
		if (isBlockOutside() || BlockFits() == false)
			currentBlock.Move(0, -1);
	}
}

void Game::MoveBlockDown() 
{
	if (!gameOver) {
		currentBlock.Move(1, 0);
		if (isBlockOutside() || BlockFits() == false) {
			currentBlock.Move(-1, 0);
			LockBlock(); //LockdN
		}
	}
}

auto Game::BlockFits()->bool
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();

	for (Position item : tiles)
		if (grid.isCellEmpty(item.row, item.col) == false)
			return false;

	return true;;
}

auto Game::isBlockOutside() -> bool
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();

	for (Position item : tiles)
		if (grid.isCellOutside(item.row, item.col))
			return true;

	return false;
}

void Game::RotateBlock()
{
	if (!gameOver) 
    {
		currentBlock.Rotate();
		if (isBlockOutside() || BlockFits() == false)
			currentBlock.UndoRotation();
		else PlaySound(rotateSound);
	}
}

void Game::LockBlock()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();

	for (Position item : tiles)
		grid.grid[item.row][item.col] = currentBlock.id;

	currentBlock = nextBlock;
	if (BlockFits() == false) gameOver = true;

	nextBlock = GetRandomBlock();
	int rowsCleared = grid.ClearFullRows();
	if (rowsCleared) 
    {
		PlaySound(clearSound);
		updateScore(rowsCleared, 0);
	}
}

void Game::Reset()
{
	grid.Init();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

void Game::updateScore(int linesCleared, int moveDownPoints)
{
	switch (linesCleared) 
    {
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	default:
		break;
	}

	score += moveDownPoints;
}
