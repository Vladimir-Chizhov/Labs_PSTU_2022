#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10;

int main()
{
    int M[N];
    srand(time(NULL));
    
    for(int i = 0; i < N; i++)
    {
        M[i] = rand() % 10;
    }
    
    cout << "Исходный массив: ";
    for(int i = 0; i < N; i++)
    {
        cout << M[i] << " ";
    }
    cout << endl;
    
    for(int i = N-1; i >= 0; i--)
    {
        if(i % 3 == 0)
        {
            for(int j = i; j < N-1; j++)
            {
                M[j] = M[j+1];
            }
            N--;
        }
    }
    
    for(int i = N-1; i >= 0; i--)
    {
        if(M[i] < 0)
        {
            int val = abs(M[i-1]) + 1;
            for(int j = N; j > i+1; j--)
            {
                M[j] = M[j-1];
            }
            M[i+1] = val;
            N++;
        }
    }
    
    cout << "Измененный массив: ";
    for(int i = 0; i < N; i++)
    {
        cout << M[i] << " ";
    }
    cout << endl;
    
    return 0;
}
