#include <iostream> 

int main()
{
    int n, factorial=1;
    int* pf = &factorial;

    std::cin >> n;

    for (int i = 1; i <=n; i++)
    {
        *pf *= i;
    }
    std::cout << "Factorial of " << n << " is " << factorial << std::endl;
}
