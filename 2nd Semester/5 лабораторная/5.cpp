#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 5;
const int COLS = 4;

void printArray(int arr[][COLS], int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteRow(int arr[][COLS], int& rows, int rowIndex)
{
    for(int i = rowIndex; i < rows-1; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            arr[i][j] = arr[i+1][j];
        }
    }
    for(int j = 0; j < COLS; j++)
    {
        arr[rows-1][j] = 0;
    }
    rows--;
}

int main()
{
    int A = 1;
    int B = 3;
    int arr[ROWS][COLS];
    srand(time(NULL));
    
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
    
    cout << "Исходный массив:\n";
    printArray(arr, ROWS);
    
    for(int i = B; i >= A; i--)
    {
        deleteRow(arr, ROWS, i);
    }
    
    cout << "Измененный массив:\n";
    printArray(arr, ROWS);
    
    return 0;
}
