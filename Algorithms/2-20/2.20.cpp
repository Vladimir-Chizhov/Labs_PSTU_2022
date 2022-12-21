#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	float n, S, a;
	int i = 1;
	bool flag = false;

	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ n" << endl;
	cin >> n;

	cout << "Ââåäèòå èñêîìûé ýëåìåíò S" << endl;
	cin >> S;

	while (i <= n && !flag)
	{
		a = sin(n + i / n);
		// äëÿ óäîáñòâà ïðîâåðêè, íå ÷àñòü àëãîðèòìà
		a = round(a * 10) / 10;
		cout << n + i / n << "|" << a << endl;
		//êîíåö óäîáñòâà
		if (a == S)
		{
			flag = true;
		}
		else
		{
			i++;
		}
	}

	if (flag)
	{
		cout << "Ýëåìåíò S åñòü ñðåäè äðóãèõ ýëåìåíòîâ ïîñëåäîâàòåëüíîñòè" << endl;
	}
	else
	{
		cout << "Ýëåìåíòà S íåò ñðåäè äðóãèõ ýëåìåíòîâ ïîñëåäîâàòåëüíîñòè" << endl;
	}

	return 0;
}
