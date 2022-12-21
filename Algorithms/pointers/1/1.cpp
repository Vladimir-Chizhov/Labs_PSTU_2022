#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	int a1;
	int a2;
	int* b1;
	int* b2;

	std::cout << "Ââåäèòå çíà÷åíèå ïåðâîé ïåðåìåííîé" << std::endl;
	std::cin >> a1;

	b1 = &a1;

	std::cout << "Ââåäèòå çíà÷åíèå âòîðîé ïåðåìåííîé" << std::endl;
	std::cin >> a2;

	b2 = &a2;

	int tmp = *b1;
	*b1 = *b2;
	*b2 = tmp;

	std::cout << "Ïîñëå çàìåíû çíà÷åíèå ïåðâîé ïåðåìåííîé ðàâíÿåòñÿ " << *b1 << std::endl;
	std::cout << "Ïîñëå çàìåíû çíà÷åíèå âòîðîé ïåðåìåííîé ðàâíÿåòñÿ " << *b2 << std::endl;

	return 0;
}
