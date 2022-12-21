#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int num1, num2;
    bool ordered = true;

    cout << "Введите первое число" << endl;
    cin >> num1;

    while (num1 != 0)
    {
        cout << "Введите следующее число" << endl;
        cin >> num2;

        if (num2 != 0 && num1 > num2)
        {
            ordered = false;
        }
        num1 = num2;
    }

    if (ordered)
    {
        cout << "Последовательность упорядочена по возрастанию." << endl;
    }
    else
    {
        cout << "Последовательность не упорядочена по возрастанию." << endl;
    }

    return 0;
}
