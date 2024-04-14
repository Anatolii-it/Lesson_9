#include <iostream>
#include <fstream>
#include <string>

std::string caesarCipher(const std::string& text, int key) {
    std::string result = "";

    for (char character : text) {
        if ((character >= '�' && character <= '�') || (character >= 'A' && character <= 'z')) {
            char base;
            if (character >= '�' && character <= '�') {
                base = isupper(character) ? '�' : '�';
                result += char(((character - base + key + 32) % 32) + base);
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
    system("chcp 1251>nul");

    std::string text = "����";
    int key = 3;
    std::string encryptedText = caesarCipher(text, key);
    std::cout << "Encrypted text: " << encryptedText << std::endl;

    return 0;
}
