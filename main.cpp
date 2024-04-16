#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string caesarCipher(const string& text, int key) {
    string result = "";

    for (char character : text) {
        if ((character >= 'А' && character <= 'я') || (character >= 'A' && character <= 'z')) {
            char base;
            if (character >= 'А' && character <= 'я') {
                base = isupper(character) ? 'А' : 'а';
                result += char(((character - base + key + 32) % 64) + base);
            }
            else {
                base = isupper(character) ? 'A' : 'a';
                result += char(((character - base + key + 26) % 26) + base);
            }
        }
        else {
            result += character;
        }
    }

    return result;
}

int main() {
    //system("chcp 1251>nul");
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Unable to open input file." << endl;
        return 1;
    }

    string inputText;
    getline(inputFile, inputText);

    inputFile.close();

    cout << "Input text from input.txt: " << inputText << endl; 

    int key = 3;

    string encryptedText = caesarCipher(inputText, key);

    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Unable to open output file." << endl;
        return 1;
    }

    outputFile << encryptedText;

    outputFile.close();

    cout << "Збережено у файл output.txt." << endl;

    return 0;
}