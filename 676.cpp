#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class MagicDictionary {
private:
    // [length, [index of the character removed, [remaining string, used
    // characters]]]
    std::unordered_map<int,
        std::unordered_map<int,
            std::unordered_map<std::string, std::unordered_set<char>>>> m_Data;
public:
    void buildDict(const std::vector<std::string>& dict) {
        for(const auto& word: dict) {
            const int LEN = word.length();
            auto& map = m_Data[LEN];
            for(int i = 0; i < LEN; ++i) {
                char ch = word[i];
                std::string r = word.substr(0, i) + word.substr(i + 1);
                map[i][r].insert(ch);
            }
        }
    }

    bool search(const std::string& word) {
        const int LEN = word.length();
        if (m_Data.find(LEN) == m_Data.end()) return false;
        auto& m_LenData = m_Data[LEN];

        for(int i = 0; i < LEN; ++i) {
            auto& lenMap = m_LenData[i];
            char ch = word[i];
            std::string r = word.substr(0, i) + word.substr(i + 1);

            auto mapIter = lenMap.find(r);
            if (mapIter == lenMap.end()) continue;

            // Corner case: if we have h[ea]llo, hello and hallo would match
            if (mapIter->second.find(ch) != mapIter->second.end() &&
                    mapIter->second.size() == 1) {
                continue;
            }

            return true;
        }
        return false;
    }
};
