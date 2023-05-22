#include <iostream>

using namespace std;

struct ListEl
{
	int data;
	ListEl* next;
	ListEl* prev;
};

ListEl* makeList(int n)
{
	ListEl* start;
	ListEl* prev, * curr;
	start = new ListEl;
	cin >> start->data;
	start->next = nullptr;
	start->prev = nullptr;
	prev = start;
	for (int i = 0; i < n - 1; i++)
	{
		curr = new ListEl;
		cin >> curr->data;
		curr->next = nullptr;
		curr->prev = prev;
		prev->next = curr;
		prev = curr;
	}
	return start;
}

void addElem(ListEl*& start, int p, int k, int& size)
{
	size++;
	ListEl* first = start;
	ListEl* last;
	for (int i = 1; i < p - 1; i++)
	{
		first = first->next;
	}
	last = first->next;

	ListEl* new_element = new ListEl;
	cout << "Введите элемент: ";
	cin >> new_element->data;

	if (p == 1)
	{
		new_element->prev = nullptr;
        start->prev = new_element;
        new_element->next = start;
        start = new_element;
	}
	else
	{
		new_element->prev = first;
       new_element->next = last;
       if (last != nullptr)
       {
           last->prev = new_element;
       }
       first->next = new_element;
	}
}

void addElems(ListEl*& list, int p, int k, int& size)
{
	for (int i = 0; i < k; i++)
	{
		addElem(list, p + i, k, size);
	}
}

void delElem(ListEl*& start, int p, int k, int& size)
{
	size--;
	ListEl* first = start;
	ListEl* last;
	
	for (int i = 1; i < p - 1; i++)
	{
		first = first->next;
	}
	last = first;
	if (p == 1)
	{
		start = start->next;
        start->prev = nullptr;
	}
	else
	{
		first->next = last->next;
        if (last->next != nullptr)
        {
            last->next->prev = first;
        }
	}
}

void delElems(ListEl*& start, int p, int k, int& size)
{
	size -= k;
	ListEl* first = start;
	ListEl* last;
	for (int i = 1; i < p - 1; i++)
	{
		first = first->next;;
	}
	last = first;

	for (int i = 0; i < k; i++)
	{
		last = last->next;
	}

	if (p == 1)
	{
		start = last;
		start->prev = nullptr;
	}
	else
	{
		first->next = last->next;
        if (last->next != nullptr)
        {
            last->next->prev = first;
        }
}

void searchElem(ListEl* start, int el)
{
	ListEl* curr = start;
	int p = 0;
	while (curr->data != el && curr->next != nullptr)
	{
		curr = curr->next;
		p++;
	}
	if (curr->data == el)
	{
		cout << "Элемент найден" << endl;
	}
	else
	{
		cout << "Элемент не найден" << endl;
	}
}

void printList(ListEl* start, int n)
{
	ListEl* curr = start;
	for (int i = 0; i < n; i++)
	{
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << endl;
}

void deleteList(ListEl* list)
{
	delete list;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int size, p, k, el;
	cout << "Введите размер списка: ";
	cin >> size;
	cout << "Введите элементы списка: ";
	ListEl* list = makeList(size);
	cout << "Список:" << endl;
	printList(list, size);
	cout << "Введите номер позиции, на которую хотите вставить новый элемнт: ";
	cin >> p;
	addElem(list, p, 1, size);
	cout << "Изменённый список:" << endl;
	printList(list, size);
	cout << "Введите номер позиции, с котрой хотите добавить новые элементы: ";
	cin >> p;
	cout << "Введите количество элементов, которые хотите добавить: ";
	cin >> k;
	addElems(list, p, k, size);
	cout << "Изменённый список:" << endl;
	printList(list, size);
	cout << "Введите номер позиции, с которой хотите удалить элемент: ";
	cin >> p;
	delElem(list, p, 1, size);
	cout << "Изменённый список:" << endl;
	printList(list, size);
	cout << "Введите номер позиции, с которой хотите удалить элементы: ";
	cin >> p;
	cout << "Введите количество элементов, которые хотите удалить: ";
	cin >> k;
	delElems(list, p, k, size);
	cout << "Изменённый список:" << endl;
	printList(list, size);
	cout << "Введите элемент, который хотите найти: ";
	cin >> el;
	searchElem(list, el);
	deleteList(list);
	return 0;
}
