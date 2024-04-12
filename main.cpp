#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream input_file("input.txt"); // Вхідний файл
    std::ofstream output_file("output.txt"); // Вихідний файл

    if (!input_file.is_open()) {
        std::cerr << "Не вдалося відкрити вхідний файл!" << std::endl;
        return 1;
    }

    if (!output_file.is_open()) {
        std::cerr << "Не вдалося відкрити вихідний файл!" << std::endl;
        return 1;
    }

    std::string word;
    while (input_file >> word) {
        if (word.length() >= 7) { // Перевірка, чи слово має не менше ніж 7 літер
            output_file << word << " "; // Запис слова у вихідний файл
        }
    }

    std::cout << "Операція завершена. Переписані слова збережено у файлі 'output.txt'." << std::endl;

    input_file.close();
    output_file.close();

    return 0;
}
