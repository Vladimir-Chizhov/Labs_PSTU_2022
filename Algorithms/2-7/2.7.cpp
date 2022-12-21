#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	int s;
	cout << "Ââåäèòå ÷èñëî N(êâàäðàò ÷èñëà)" << endl;
	cin >> n;
	s = sqrt(n);
	if (s * s != n)
	{
		cout << "Ââåäèòå êîððåêòíîå çíà÷åíèå N" << endl;
	}
	else
	{
		//çàïîëíåííûé êâàäðàò èç N çâ¸çäî÷åê
		for (int i = 1; i <= s; i++) // ïî ñòðîêàì
		{
			for (int j = 1; j <= s; j++) // ïî ñòîëáöàì
			{
				cout << "* ";
			}
			cout << endl; // ïåðåõîä íà íîâóþ ñòðîêó
		}
	}
	cin >> n;
	    //çàïîëíåííûé êâàäðàò ñî ñòîðîé N
	for (int i = 1; i <= n; i++) // ïî ñòðîêàì
	{
		for (int j = 1; j <= n; j++) // ïî ñòîëáöàì
		{
			cout << "* ";
		}
		cout << endl; // ïåðåõîä íà íîâóþ ñòðîêó
	}
	cout << endl;
	cin >> n;
	int numofspaces=n-2;

	for (int i = 1; i <= n; i++) // íåçàïîëíåííûé êâàäðàò
	{
		if ((i == n) || (i == 1))
		{
			for (int j = 1; j <= n; j++)
			{
				cout << "* ";
			}

			cout << endl;

		}
		else
		{
			cout << "* ";
			for (int j = 1; j <= numofspaces; j++)
			{
				cout << "  ";

			}
			cout << "* " << endl;

		}
	}

	return 0;
}

