#include <array>
#include <string>
#include <vector>


std::vector<int> partitionLabels(const std::string& S) {
    const int LEN = S.length();

    // First we need to find the last position of each unique character.
    std::array<int, 26> characterLastPos;
    std::fill(characterLastPos.begin(), characterLastPos.end(), 0);

    for(size_t i = 0; i < S.length(); ++i) {
        characterLastPos[S[i] - 'a'] = i;
    }

    int i = 0;
    int lastest = 0;
    int lastPos = 0;
    std::vector<int> range;
    while(i < LEN) {
        char ch = S[i];
        lastest = std::max(lastest, characterLastPos[ch - 'a']);
        if (i == lastest) {
            range.push_back(i - lastPos + 1);
            lastPos = i + 1;
        }
        ++i;
    }

    return range;
}
