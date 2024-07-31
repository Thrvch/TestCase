#include "word.h"
#include <iostream>
#include <string>

int main() {
    std::string text;
    std::cout << "Enter a text: ";
    std::getline(std::cin, text);

    auto result = count_words(text);

    for (const auto& pair : result.get_counts()) {
        std::cout << "Words of length " << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
