#include <iostream>

int main()
{
	int n;
	int* ptr1 = &n;
	int* ptr2 = &n;

	std::cin >> n;

	std::cin >> *ptr2;

	*ptr1 = *ptr2;

	std::cout << n << std::endl;

	return 0;
}
