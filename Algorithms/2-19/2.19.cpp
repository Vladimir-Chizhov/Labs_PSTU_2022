#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int N;
	int S = 0;
	
	cout << "Ââåäèòå êîëè÷åñòâî ñëàãàåìûõ N" << endl;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		if (i % 3 == 0)
		{
			S -= i;
		}
		else
		{
			S += i;
		}
			
	}
	cout << "Ñóììà S ðàâíà:" << S << endl;

	return 0;
}
