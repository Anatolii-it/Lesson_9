#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encryptCaesarCipher(const string& text, int shift) {
    string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            result += static_cast<char>((c - base + shift) % 26 + base);
        }
        else {
            result += c; 
        }
    }

    return result;
}

int main() {
    ifstream input_file("input.txt"); 
    ofstream output_file("output.txt");

    if (!input_file.is_open()) {
        cerr << "Не вдалося відкрити вхідний файл!" << endl;
        return 1;
    }

    if (!output_file.is_open()) {
        cerr << "Не вдалося відкрити вихідний файл!" << endl;
        return 1;
    }

    int key = 3; // Ключ

    string line;
    while (getline(input_file, line)) {
        string encrypted_line = encryptCaesarCipher(line, key);
        output_file << encrypted_line << endl;
    }

    cout << "Записано у файл 'output.txt'." << endl;

    input_file.close();
    output_file.close();

    return 0;
}
