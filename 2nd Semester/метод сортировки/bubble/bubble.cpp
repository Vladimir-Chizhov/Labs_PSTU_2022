#include <iostream>
using namespace std;

int main()
{
	int tmp;
	const int SIZE = 11;
	int arr[] = { 41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 25 };
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << endl;
	}
}
