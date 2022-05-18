#include <iostream>


int main(int argc, char** argv)
{
	const int ROWS = 3;
	const int COLS = 5;

	const char* grid2D[ROWS][COLS] =
	{
		{ "a0", "a1", "a2", "a3", "a4" },
		{ "b0", "b1", "b2", "b3", "b4" },
		{ "c0", "c1", "c2", "c3", "c4" },
	};

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			std::cout << grid2D[i][j] << " ";
		}
		std::cout << std::endl;
	} std::cout << std::endl;

	for (int index = 0; index < ROWS * COLS; index++)
	{
		int rowIndex = index / COLS;
		int colIndex = index % COLS;

		std::cout << grid2D[rowIndex][colIndex] << ", ";
	}	std::cout << std::endl << std::endl;


	const char* grid1D[ROWS * COLS] =
	{
		"a0", "a1", "a2", "a3", "a4",
		"b0", "b1", "b2", "b3", "b4",
		"c0", "c1", "c2", "c3", "c4"
	};

	for (int rowIndex = 0; rowIndex < ROWS; rowIndex++)
	{
		for (int colIndex = 0; colIndex < COLS; colIndex++)
		{
			int index = rowIndex * COLS + colIndex;

			std::cout << grid1D[index] << ", ";
		}
		std::cout << std::endl;
	}
}

