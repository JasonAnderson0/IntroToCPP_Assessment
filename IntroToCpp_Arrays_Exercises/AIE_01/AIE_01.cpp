
#include <iostream>

int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 5;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50 };

	//iterates through the array and prints every value to the console
	for (int i = 0; i < NUM_NUMBERS; i++)
	{
		std::cout << numbers[i] << ", ";
	} std::cout << std::endl;

	//iterates through the array backwards and prints every value to the console
	for (int i = NUM_NUMBERS-1; i >= 0; i--)
	{
		std::cout << numbers[i] << ", ";
	}

	return 0;
}
