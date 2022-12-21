#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
    int n, num, max, min;

    cout << "Ââåäèòå êîëè÷åñòâî ÷èñåë ïîñëåäîâàòåëüíîñòè" << endl;
    cin >> n;

    cout << "Ââåäèòå ïåðâîå ÷èñëî:" << endl;
    cin >> num;
    max = num;
    min = num;

    for (int i = 2; i <= n; i++)
    {
        cout << "Ââåäèòå ñëåäóþùåå ÷èñëî" << endl;
        cin >> num;
        if (num > max)
        {
            max = num;
        }
        else if (num < min)
        {
            min = num;
        }
    }
    cout << "Ñóììà ìàêñèìàëüíîãî è ìèíèìàëüíîãî ýëåìåíòîâ: " << (max + min) << endl;

    return 0;
}
