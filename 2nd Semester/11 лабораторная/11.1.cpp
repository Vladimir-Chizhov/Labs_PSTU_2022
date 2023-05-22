#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    // добавление элемента в конец списка
    void addNode(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    // вывод списка на экран
    void printList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // удаление элемента по номеру
    void deleteNode(int pos) {
        if (pos == 1) {
            Node* delNode = head;
            head = head->next;
            delete delNode;
        }
        else {
            Node* prev = head;
            for (int i = 1; i < pos - 1; i++) {
                prev = prev->next;
            }
            Node* delNode = prev->next;
            prev->next = delNode->next;
            delete delNode;
        }
    }

    // добавление K элементов, начиная с заданной позиции
    void insertNodes(int pos, int K) {
        Node* prev = head;
        for (int i = 1; i < pos; i++) {
            prev = prev->next;
        }
        for (int i = 1; i <= K; i++) {
            Node* newNode = new Node(rand() % 100);
            newNode->next = prev->next;
            prev->next = newNode;
            prev = newNode;
        }
    }
};

int main() {
    LinkedList list;
    for (int i = 1; i <= 10; i++) {
        list.addNode(i);
    }

    cout << "Исходный список: ";
    list.printList();

    list.deleteNode(3);
    cout << "Список после удаления элемента №3: ";
    list.printList();

    list.insertNodes(5, 3);
    cout << "Список после вставки 3 элементов, начиная с №5: ";
    list.printList();

    return 0;
}
