#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
	nrRows = 20;
	nrCols = 10;
	cellSize = 30;
	Init();
	colors = GetCellColors();

}

void Grid::Init()
{
	for (int row = 0; row < nrRows; row++)
		for (int col = 0; col < nrCols; col++)
			grid[row][col] = 0;
}

void Grid::Print()
{
	for (int row = 0; row < nrRows; row++, std::cout << '\n')
		for (int col = 0; col < nrCols; col++)
			std::cout << grid[row][col] << " ";
}

void Grid::Draw()
{
	for (int row = 0; row < nrRows; row++) {
		for (int col = 0; col < nrCols; col++)
		{
			int cellVal = grid[row][col];
			DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellVal]);
		}
	}

}

auto Grid::isCellOutside(int row, int col)->bool
{
	if (row >= 0 && row < nrRows && col >= 0 && col < nrCols)
		return false;
	return true;
}

auto Grid::isCellEmpty(int row, int col)->bool
{
	if (grid[row][col] == 0)
		return true;
	return false;
}

auto Grid::ClearFullRows()->int
{
	int completed = 0;
	for (int row = nrRows - 1; row >= 0; row--)
	{
		if (isRowFull(row)) {
			ClearRow(row);
			completed++;
		}
		else if (completed > 0)
			MoveRowDown(row, completed);
	}
	return completed;
}

auto Grid::isRowFull(int row)->bool
{
	for (int col = 0; col < nrCols; col++)
		if (grid[row][col] == 0)
			return false;

	return true;
}

void Grid::ClearRow(int row)
{
	for (int col = 0; col < nrCols; col++)
		grid[row][col] = 0;
}

void Grid::MoveRowDown(int row, int nrRows)
{
	for (int col = 0; col < nrCols; col++) {
		grid[row + nrRows][col] = grid[row][col];
		grid[row][col] = 0;
	}
}
