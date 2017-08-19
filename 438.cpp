#include <array>
#include <string>
#include <vector>


std::vector<int> findAnagrams(const std::string& s, const std::string& p) {
    const int LENP = p.size();
    const int LENS = s.size();

    std::vector<int> result;

    if (LENP > LENS) return result;

    std::array<int, 26> pCount;
    std::fill(pCount.begin(), pCount.end(), 0);
    for(auto c: p) {
        ++pCount[c - 'a'];
    }

    std::array<int, 26> sCount;
    std::fill(sCount.begin(), sCount.end(), 0);
    int i = 0;
    while(i < LENP) {
        ++sCount[s[i++] - 'a'];
    }
    int j = 0;

    while(i <= LENS) {
        bool match = true;
        for(int v = 0; v < 26; ++v)
            if (pCount[v] != sCount[v]) {
                match = false;
                break;
            }
        if (match) result.push_back(j);

        if (s[i]) ++sCount[s[i] - 'a'];
        ++i;
        --sCount[s[j++] - 'a'];
    }

    return result;
}
