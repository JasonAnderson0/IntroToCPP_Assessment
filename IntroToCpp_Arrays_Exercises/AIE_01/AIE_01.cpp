
#include <iostream>

int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 5;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50 };

	
	for (int i = 0; i < NUM_NUMBERS; i++)
	{
		std::cout << numbers[i] << ", ";
	} std::cout << std::endl;

	
	for (int i = NUM_NUMBERS-1; i >= 0; i--)
	{
		std::cout << numbers[i] << ", ";
	}
	system("pause");
	return 0;
}
