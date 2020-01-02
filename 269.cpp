#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

std::string alienOrder(const std::vector<std::string>& words) {
    // Standard toplogical sort
    const int NWORDS = words.size();
    std::unordered_map<char, std::unordered_set<char>> edges;
    for (int i = 1; i < NWORDS; ++i) {
        const int LEN = std::min(words[i].size(), words[i - 1].size());
        for (int x = 0; x < LEN; ++x) {
            if (words[i][x] != words[i - 1][x]) {
                edges[words[i - 1][x]].insert(words[i][x]);
                break;
            }
        }
    }

    std::unordered_map<char, int> inDegree;
    for (auto& word: words) for(auto ch: word) inDegree[ch] = 0;
    for (auto edge: edges) {
        for (auto t: edge.second) {
            if (inDegree.find(t) == inDegree.end()) inDegree[t] = 0;
            ++inDegree[t];
        }
    }

    // Now do the sort
    std::string result;
    while (!inDegree.empty()) {
        char inDegreeZeroChar = '\0';
        for (auto i: inDegree) {
            if (i.second == 0) {
                inDegreeZeroChar = i.first;
                break;
            }
        }
        // Cyclic DAG
        if (inDegreeZeroChar == 0) {
            return "";
        }

        for (auto c: edges[inDegreeZeroChar]) {
            --inDegree[c];
        }

        edges.erase(inDegreeZeroChar);
        inDegree.erase(inDegreeZeroChar);

        result.push_back(inDegreeZeroChar);
    }

    return result;
}
