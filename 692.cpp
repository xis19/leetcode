#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

std::vector<std::string> topKFrequent(const std::vector<std::string>& words, int k) {
    std::unordered_map<std::string, int> counter;
    for(const auto& word: words)
        ++counter[word];


    auto comp = [&](const std::pair<int, std::string>& s1, const std::pair<int, std::string>& s2) -> bool {
        return (s1.first > s2.first) || (s1.first == s2.first && s1.second < s2.second);
    };

    std::vector<std::pair<int, std::string>> vec;
    std::make_heap(vec.begin(), vec.end(), comp);
    for(auto& i: counter) {
        vec.emplace_back(std::make_pair(i.second, i.first));
        std::push_heap(vec.begin(), vec.end(), comp);
    }

    std::vector<std::string> result;
    for(int i = 0; i < k; ++i) {
        std::pop_heap(vec.begin(), vec.end(), comp);
        result.push_back(vec.back().second);
        vec.pop_back();
    }

    return result;
}
