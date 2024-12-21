#include "Block.h"

Block::Block() 
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	rOffset = 0, cOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
	std::vector<Position> tiles = GetCellPositions();
	for (Position item : tiles)
		DrawRectangle(item.col * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
}

void Block::Move(int rows, int cols) 
{
	rOffset += rows;
	cOffset += cols;
}

auto Block::GetCellPositions()->std::vector<Position> 
{
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;
	for (Position item : tiles)
	{
		Position newPos = Position(item.row + rOffset, item.col + cOffset);
		movedTiles.push_back(newPos);
	}
	return movedTiles;
}

void Block::Rotate()
{
	rotationState++;
	if (rotationState == (int)cells.size())
		rotationState = 0;
}

void Block::UndoRotation()
{
	rotationState--;
	if (rotationState == -1)
		rotationState = cells.size() - 1;
}
