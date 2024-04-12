#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file1("file1.txt"); 
    ifstream file2("file2.txt");

    if (!file1.is_open() || !file2.is_open()) {
        cerr << "Не вдалося відкрити один або обидва файли!" << endl;
        return 1;
    }

    string line1, line2;
    int lineNumber = 0;
    bool mismatch = false;

    while (getline(file1, line1) && getline(file2, line2)) {
        lineNumber++;

        if (line1 != line2) {
            cout << "Рядок " << lineNumber << " не збігається:" << endl;
            cout << "З файлу 1: " << line1 << endl;
            cout << "З файлу 2: " << line2 << endl;
            mismatch = true;
        }
    }

    if (!file1.eof() || !file2.eof()) {
        cout << "Різна кількість рядків" << endl;
        mismatch = true;
    }

    if (!mismatch) {
        cout << "Усі рядки однакові" << endl;
    }

    file1.close();
    file2.close();

    return 0;
}
