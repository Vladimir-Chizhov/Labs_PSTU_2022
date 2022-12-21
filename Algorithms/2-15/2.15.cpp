#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    int N, S, k;
    bool flag = false;

    cout << "Ââåäèòå ÷èñëî N è ÷èñëî S" << endl;
    cin >> N >> S;

    while (N > 0 && !flag)
    {
        k = N % 10;
        if (k == S)
        {
            flag = true;
            cout << "×èñëî S âõîäèò â çàïèñü ÷èñëà N" << endl;
        }
        else
        {
            N /= 10;
        }
    }

    if (!flag)
    {
        cout << "×èñëî S íå âõîäèò â çàïèñü ÷èñëà N" << endl;
    }

    return 0;
}
