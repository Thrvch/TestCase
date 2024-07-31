#include "word_count_map.h"
#include <algorithm>

void WordCountMap::increment(size_t length) {
    auto it = std::find_if(counts.begin(), counts.end(),
                           [length](const auto& pair) { return pair.first == length; });
    if (it != counts.end()) {
        it->second++;
    } else {
        counts.emplace_back(length, 1);
    }
}

size_t WordCountMap::size() const {
    return counts.size();
}

size_t WordCountMap::count(size_t length) const {
    auto it = std::find_if(counts.begin(), counts.end(),
                           [length](const auto& pair) { return pair.first == length; });
    return it != counts.end() ? it->second : 0;
}

std::vector<std::pair<size_t, size_t>> WordCountMap::get_counts() const {
    return counts;
}
