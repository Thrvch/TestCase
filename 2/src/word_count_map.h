#ifndef WORD_COUNT_MAP_H
#define WORD_COUNT_MAP_H

#include <cstddef>
#include <utility>
#include <vector>

class WordCountMap {
public:
    void increment(size_t length);
    size_t size() const;
    size_t count(size_t length) const;
    std::vector<std::pair<size_t, size_t>> get_counts() const;

private:
    std::vector<std::pair<size_t, size_t>> counts;
};

#endif // WORD_COUNT_MAP_H
