#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

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

    vector<string> lines;
    string line;
    while (getline(input_file, line)) {
        lines.push_back(line);
    }

    for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
        output_file << *it << endl;
    }

    cout << "Операція завершена. Рядки було записано у зворотньому порядку у файлі 'output.txt'." << endl;

    input_file.close();
    output_file.close();

    return 0;
}
