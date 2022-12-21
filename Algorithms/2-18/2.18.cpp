#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int N;
	int r = 0; // reversed
	
	cout << "Ââåäèòå íàòóðàëüíîå ÷èñëî N" << endl;
	cin >> N;

	while (N > 0)
	{
		r = r * 10 + N % 10;
		N /= 10;
	}
	cout <<"Ââåäåííîå ÷èñëî â îáðàòíîì ïîðÿäêå áóäåò âûãëÿäåòü òàê: " << r << endl;

	return 0;
}
