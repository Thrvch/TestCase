#include "word.h"
#include <sstream>
#include <algorithm>
#include <cctype>

WordCountMap count_words(const std::string& text) {
    WordCountMap word_lengths;
    std::istringstream stream(text);
    std::string token;

    while (stream >> token) {

        token.erase(token.begin(), std::find_if(token.begin(), token.end(), [](unsigned char ch) {
            return !std::ispunct(ch);
        }));

        token.erase(std::find_if(token.rbegin(), token.rend(), [](unsigned char ch) {
            return !std::ispunct(ch);
        }).base(), token.end());

        if (!token.empty()) {
            word_lengths.increment(token.length());
        }
    }

    return word_lengths;
}
