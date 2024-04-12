#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

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

    int char_count = 0; 
    int line_count = 0;
    int vowel_count = 0;
    int consonant_count = 0;
    int digit_count = 0; 

    string line;
    while (getline(input_file, line)) {
        char_count += line.length(); 

        for (char c : line) {
            if (isalpha(c)) { // Перевіряємо, чи символ є буквою
                char lower_c = tolower(c); // робимо усі маленьки
                if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
                    vowel_count++; // Голосна буква
                }
                else {
                    consonant_count++; // Приголосна буква
                }
            }
            else if (isdigit(c)) {
                digit_count++; // цифри
            }
        }

        line_count++; //  рядки
    }

    
    output_file << "Кількість символів: " << char_count << endl;
    output_file << "Кількість рядків: " << line_count << endl;
    output_file << "Кількість голосних букв: " << vowel_count << endl;
    output_file << "Кількість приголосних букв: " << consonant_count << endl;
    output_file << "Кількість цифр: " << digit_count << endl;

    cout << "Записано у файл 'output.txt'." << endl;

    input_file.close();
    output_file.close();

    return 0;
}
