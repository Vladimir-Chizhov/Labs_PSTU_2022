#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, numofstars;
	
	cout << "Ââåäèòå ÷èñëî N(íàòóðàëüíîå è ÷èñëî äîëæíî áûòü áîëüøå 2)" << endl;
	cin >> n;

	if (n <= 2)
	{
		cout << "Ââåäèòå êîððåêòíîå çíà÷åíèå N" << endl;
	}

	numofstars = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= numofstars; j++)
		{
			cout << "* ";
		}

		numofstars++;

		cout << endl;

	}

	return 0;
}
