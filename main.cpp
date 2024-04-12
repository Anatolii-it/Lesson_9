#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");

    if (!input_file.is_open()) {
        cerr << "EROR input.txt" << endl;
        return 1;
    }

    if (!output_file.is_open()) {
        cerr << "EROR output.txt" << endl;
        return 1;
    }

    string word;
    while (input_file >> word) {
        if (word.length() > 0) {
            output_file << word << " ";
        }
    }

    cout << "Операція завершена. создан 'output.txt'." << endl;

    input_file.close();
    output_file.close();

    return 0;
}
