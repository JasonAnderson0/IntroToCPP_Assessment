#include <iostream>
#include <string>

const int* BinarySearch(const int* arr, int count, int searchVal);
void TestResult(const int* result, int* const expected);


int main(int argc, char** argv)
{
	const int NUM_ITEMS = 8;
	int arr1[NUM_ITEMS] = { 1, 3, 5, 7, 9, 11, 13, 15 };

	TestResult( BinarySearch(arr1, NUM_ITEMS, 9),  &arr1[4]   );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 1),  &arr1[0]   );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 15), &arr1[7]   );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 0),  nullptr    );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 16), nullptr    );

	system("pause");
	return 0;
}

void TestResult(const int* result, int* const expected)
{
	if (result == expected)
	{
		std::cout << "PASS: result(" <<
			(result == nullptr ? "nullptr" : std::to_string(*result).c_str()) << ")" << std::endl;
		return;
	}

	std::cout << "FAIL: received(" <<
		(result == nullptr ? "nullptr" : std::to_string(*result).c_str()) << ") expected(" <<
		(expected == nullptr ? "nullptr" : std::to_string(*expected).c_str()) << ")" << std::endl;
}

const int* BinarySearch(const int* arr, int count, int searchVal)
{
	int L = 0;
	int R = count - 1;
	int M = (int)((count + L) / 2);

	while (L <= R)
	{
		if (arr[M] == searchVal)
		{
			return &arr[M];
		}
		if (arr[M] < searchVal)
		{
			M += 1;
		}
		if (arr[M] > searchVal)
		{
			M -= 1;
		}
	}
	return nullptr;
}