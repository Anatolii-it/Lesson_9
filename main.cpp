#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <array>
#include <vector>
#include <locale>
#include <fstream>
#include <streambuf>

using namespace std;

void CaesarIn(int k) {
    ifstream input("input.txt");
    ofstream output("caesarin.txt");

    char buff;
    int iter;

    if (!input.is_open())
        cout << "Файл не может быть открыт!\n";
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
    int iter;

    if (!input.is_open())
        cout << "Файл не может быть открыт!\n";
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

void MonoAlphabetIn(int k)
{
    ifstream input("input.txt");
    ofstream output("monoalp.txt");

    char buff;
    int iter;

    if (!input.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        while (!input.eof()) {
            buff = input.get();
            if (buff == ' ')
                output << ' ';
            if (buff == '\n')
                output << '\n';
            if (buff >= 'A' && buff <= 'Z') {
                iter = int(buff) - int('A');
                iter = (iter + k) % 26;
                iter += (int)'A';
                output << char(iter);
            }
            if (buff >= 'a' && buff <= 'z') {
                iter = int(buff) - int('a');
                iter = (iter + k) % 26;
                iter += (int)'a';
                output << char(iter);
            }
            if (buff >= 'А' && buff <= 'Я') {
                iter = int(buff) - int('А');
                iter = (iter + k) % 32;
                iter += (int)'А';
                output << char(iter);
            }
            if (buff >= 'а' && buff <= 'я') {
                iter = int(buff) - int('а');
                iter = (iter + k) % 32;
                iter += (int)'а';
                output << char(iter);
            }
        }
    }
    input.close();
    output.close();
}

void MonoAlphabetOut(int k)
{
    ifstream input("monoalp.txt");
    ofstream output("monoalpout.txt");

    char buff;
    int iter;

    if (!input.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        while (!input.eof()) {
            buff = input.get();
            if (buff == ' ')
                output << ' ';
            if (buff == '\n')
                output << '\n';
            if (buff >= 'A' && buff <= 'Z') {
                iter = int(buff) - int('A');
                iter = (iter - k + 26) % 26;
                iter += (int)'A';
                output << char(iter);
            }
            if (buff >= 'a' && buff <= 'z') {
                iter = int(buff) - int('a');
                iter = (iter - k + 26) % 26;
                iter += (int)'a';
                output << char(iter);
            }
            if (buff >= 'А' && buff <= 'Я') {
                iter = int(buff) - int('А');
                iter = (iter - k + 32) % 32;
                iter += (int)'А';
                output << char(iter);
            }
            if (buff >= 'а' && buff <= 'я') {
                iter = int(buff) - int('а');
                iter = (iter - k + 32) % 32;
                iter += (int)'а';
                output << char(iter);
            }
        }
    }
    input.close();
    output.close();
}

int main()
{
    //setlocale(LC_ALL, "Russian");

    int k = 0;
    cout << "Сдвиг: ";
    cin >> k;

    if (k < 1)
        return 0;

    cout << "Шифровка Цезарь. " << '\n';
    CaesarIn(k);
    cout << "Дешифровка Цезарь." << '\n';
    CaesarOut(k);

    cout << "Шифровка Моноалфавит. " << '\n';
    MonoAlphabetIn(k);
    cout << "Дешифровка Моноалфавит." << '\n';
    MonoAlphabetOut(k);

    return 0;
}