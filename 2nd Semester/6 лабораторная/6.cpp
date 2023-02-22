#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int MAX_LEN = 255;
    char s[MAX_LEN];

    cout << "Введите строку: ";
    gets(s);

    char* first_word = strtok(s, " .");
    if (first_word != nullptr) {
        char* current_word = strtok(nullptr, " .");
        while (current_word != nullptr) {
            if (strcmp(first_word, current_word) == 0) {
                cout << current_word << endl;
            }
            current_word = strtok(nullptr, " .");
        }
    }

    return 0;
}
