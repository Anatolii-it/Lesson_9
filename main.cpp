#include <iostream>
#include <fstream>
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

    string line;
    bool added_separator = false;
    while (getline(input_file, line)) {
        output_file << line << endl;
        if (line.find_first_not_of(" \t") == string::npos && !added_separator) { 
            output_file << "------------" << endl;
            added_separator = true;
        }
    }

    if (!added_separator) { 
        output_file << "------------" << endl;
    }

    cout << "записано у файл 'output.txt'." << endl;

    input_file.close();
    output_file.close();

    return 0;
}
