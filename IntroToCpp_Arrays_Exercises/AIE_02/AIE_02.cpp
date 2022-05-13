#include <iostream>

int MinValue(const int* arr, int count);
int MaxValue(const int* arr, int count);
int CountOccurencesOfValue(const int* arr, int count, int search);


int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 10;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50, 10, 20, 30, 40, 50 };

	std::cout << "Expected: 10 - Got: " << MinValue(numbers, NUM_NUMBERS) << std::endl;
	std::cout << "Expected: 50 - Got: " << MaxValue(numbers, NUM_NUMBERS) << std::endl;
	std::cout << "Expected: 2 - Got: " << CountOccurencesOfValue(numbers, NUM_NUMBERS, 10) << std::endl;
	std::cout << "Expected: 0 - Got: " << CountOccurencesOfValue(numbers, NUM_NUMBERS, 8) << std::endl;

	return 0;
}


int MinValue(const int* arr, int count)
{
	int smallest = arr[0];

	for (int i = 0; i < count; i++) {
		if (arr[i] < smallest)
			smallest = arr[i];
	}
	return smallest;
}

int MaxValue(const int* arr, int count)
{
	int largest = arr[0];

	for (int i = 0; i < count; i++) {
		if (arr[i] > largest)
			largest = arr[i];
	}
	return largest;
}

int CountOccurencesOfValue(const int* arr, int count, int search)
{
	int occurances = 0;

	for (int i = 0; i < count; i++)
	{
		if (arr[i] == search) {
			occurances++;
		}
	}

	return occurances;
}

