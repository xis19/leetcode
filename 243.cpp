#include <limits>
#include <string>
#include <vector>


int shortestDistance(const std::vector<std::string>& words, const std::string& word1, const std::string& word2) {
    std::vector<int> w1Index, w2Index;
    for(size_t i = 0; i < words.size(); ++i) {
        if (words[i] == word1) w1Index.push_back(i);
        if (words[i] == word2) w2Index.push_back(i);
    }

    int distance = std::numeric_limits<int>::max();
    for(auto i1: w1Index) {
        for(auto i2: w2Index) {
            distance = std::min(distance, std::abs(i1 - i2));
        }
    }
    return distance;
}
