#include <iostream>
#include <fstream>

using namespace std;

void CaesarIn(int k) {
    ifstream input("input.txt");
    ofstream output("caesarin.txt");

    char buff;

    if (!input.is_open())
        cout << "Файл не може бути відкритий!\n";
    else {
        while (!input.eof()) {
            buff = input.get();
            if (buff == ' ')
                output << ' ';
            if (buff == '\n')
                output << '\n';

            if (buff >= 'A' && buff <= 'Z') {
                buff += (k % 26);
                if (buff > 'Z')
                    buff -= 26;
                output << buff;
            }
            if (buff >= 'a' && buff <= 'z') {
                buff += (k % 26);
                if (buff > 'z')
                    buff -= 26;
                output << buff;
            }
            if (buff >= 'А' && buff <= 'Я') {
                buff += (k % 33);
                if (buff > 'Я')
                    buff -= 33;
                output << buff;
            }
            if (buff >= 'а' && buff <= 'я') {
                buff += (k % 33);
                if (buff > 'я')
                    buff -= 33;
                output << buff;
            }
        }
    }
    input.close();
    output.close();
}

void CaesarOut(int k) {
    ifstream input("caesarin.txt");
    ofstream output("caesarout.txt");

    char buff;

    if (!input.is_open())
        cout << "Файл не може бути відкритий!\n";
    else {
        while (!input.eof()) {
            buff = input.get();
            if (buff == ' ')
                output << ' ';
            if (buff == '\n')
                output << '\n';

            if (buff >= 'A' && buff <= 'Z') {
                buff -= (k % 26);
                if (buff > 'Z')
                    buff += 26;
                output << buff;
            }
            if (buff >= 'a' && buff <= 'z') {
                buff -= (k % 26);
                if (buff > 'z')
                    buff += 26;
                output << buff;
            }
            if (buff >= 'А' && buff <= 'Я') {
                buff -= (k % 33);
                if (buff > 'Я')
                    buff += 33;
                output << buff;
            }
            if (buff >= 'а' && buff <= 'я') {
                buff -= (k % 33);
                if (buff > 'я')
                    buff += 33;
                output << buff;
            }
        }
    }
    input.close();
    output.close();
}

int main() {
    int k = 0;
    cout << "Сдвиг: ";
    cin >> k;

    if (k < 1)
        return 0;

    cout << "Шифрування Цезаря. " << '\n';
    CaesarIn(k);
    cout << "Дешифрування Цезаря." << '\n';
    CaesarOut(k);

    system("pause");
    return 0;
}
