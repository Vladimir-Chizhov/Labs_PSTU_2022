#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, max, num;
	cout << "Ââåäèòå êîëè÷åñòâî ÷èñåë ïîñëåäîâàòåëüíîñòè" << endl;
	cin >> n;
	cout << "Ââåäèòå ïåðâîå ÷èñëî" << endl;
	cin >> max;

	for (int i = 2; i <= n; i++)
	{
		cout << "Ââåäèòå ñëåäóþùåå ÷èñëî" << endl;
		cin >> num;

		if (num > max)
		{
			max = num;
		}
	}

	cout << "Ìàêñèìàëüíûé ýëåìåíò: " << max << endl;

	return 0;
}
