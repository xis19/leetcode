#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

// A -- 0b00
// C -- 0b01
// T -- 0b10
// G -- 0b11

const int SEQ_LEN = 10;

std::unordered_map<char, int> MAPPER = {
    {'A', 0},
    {'C', 1},
    {'T', 2},
    {'G', 3}
};

std::unordered_map<int, char> REV_MAPPER = {
    {0, 'A'},
    {1, 'C'},
    {2, 'T'},
    {3, 'G'}
};

std::vector<std::string> findRepeatedDnaSequences(const std::string& s) {
    const int S_LEN = s.size();
    std::vector<std::string> result;
    if (S_LEN < SEQ_LEN) return result;

    std::unordered_map<int, int> mapper;

    int value = 0;
    int iter = 0;
    for(;iter < SEQ_LEN; ++iter) {
        value <<= 2;
        value |= MAPPER[s[iter]];
    }
    mapper[value] = 1;

    while(iter < S_LEN) {
        value <<= 2;
        value |= MAPPER[s[iter]];
        // 0b11111111111111111111
        value &= 1048575;

        if (mapper.count(value) == 0) {
            mapper[value] = 1;
        } else {
            ++mapper[value];
        }
        ++iter;
    }

    for(auto kvpair: mapper) {
        if (kvpair.second == 1) continue;

        std::string seq;
        int value = kvpair.first;

        for(int i = 0; i < SEQ_LEN; ++i) {
            seq.push_back(REV_MAPPER[value & 3]);
            value >>= 2;
        }

        std::reverse(seq.begin(), seq.end());
        result.emplace_back(seq);
    }

    return result;
}
