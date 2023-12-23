#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';' || c == '-';
}

std::string removeExtraSpacesAndPunctuation(const std::string& input) {
    std::string result;
    bool previousWasSpace = false;
    for (char c : input) {
        if (c == ' ' && previousWasSpace) {
            continue;
        } else if (c == ' ') {
            result += c;
            previousWasSpace = true;
        } else if (isPunctuation(c)) {
            if (!previousWasSpace) {
                result += ' ';
            }
            previousWasSpace = false;
        } else {
            result += std::tolower(c);
            previousWasSpace = false;
        }
    }
    return result;
}

int main() {
    std::string input;
    std::cout << "Введите последовательность слов (разделенных пробелами, заканчивающихся точкой): ";
    std::getline(std::cin, input);

    input = removeExtraSpacesAndPunctuation(input);

    std::vector<std::string> words;
    size_t pos = 0;
    while ((pos = input.find(' ', pos)) != std::string::npos) {
        words.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    words.push_back(input.substr(0, input.size())); // Убрать точку в конце

    std::sort(words.begin(), words.end());

    std::cout << "Слова в алфавитном порядке:\n";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::cout << "Слова исходной последовательности:\n";
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
