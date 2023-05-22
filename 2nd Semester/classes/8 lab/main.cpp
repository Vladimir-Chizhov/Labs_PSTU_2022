#include <iostream>
#include "Dialog.h"
#include "Windows.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	cout << "+ - Äîáàâèòü ýëåìåíò" << "\n";
	cout << "- - Óäàëèòü ýëåìåíò" << "\n";
	cout << "m - Ñîçäàòü ãðóïïó(m2 - èç 2 ýëåìåíòîâ)" << "\n";
	cout << "s - Ïðîñìîòð ãðóïïû" << "\n";
	cout << "? - Âûâåñòè îïðåäåëåííûé ýëåìåíò(?1 - íîìåð 1)" << "\n";
	cout << "q - êîíåö" << endl;
	Dialog D;
	D.Execute();
	return 0;
}
