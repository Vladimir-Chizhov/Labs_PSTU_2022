#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int n, num;
    bool plusFirst = false; 
    bool minusFirst = false;

    cout << "Ââåäèòå êîëè÷åñòâî ÷èñåë ïîñëåäîâàòåëüíîñòè" << endl;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        if (!plusFirst && !minusFirst)
        {
            if (num > 0) 
            { 
                plusFirst = true; 
            }
            else if (num < 0) 
            { 
                minusFirst = true; 
            }
        }
    }

    if (plusFirst)
    {
        cout << "Ñíà÷àëà ââåëè ïîëîæèòåëüíîå ÷èñëî";
    }
    else if (minusFirst)
    {
        cout << "Ñíà÷àëà ââåëè îòðèöàòåëüíîå ÷èñëî";
    }
    else
    {
        cout << "Âñå ýëåìåíòû áûëè íóëåâûìè";
    }
    cout << endl;

	return 0;
}
