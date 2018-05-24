#include <limits>
#include <string>
#include <vector>

std::string minWindow(const std::string& S, const std::string& T) {
    // For this one, we cannot use two pointer strategy since we have
    // to preserve the order of the characters in the string.

    // We consider the example
    //    a b c d e b d d e
    // b    1       1
    // d        3     2 3
    // e          4       4
    //
    // For a new character, we find the nearest match in the prior row. Finally
    // we backtrack the last row to find the first match.
    const int LEN_S = S.size();
    const int LEN_T = T.size();

    std::vector<std::vector<int>> dp(LEN_T, std::vector<int>(LEN_S, 0));
    for(int i = 0; i < LEN_T; ++i) {
        for(int j = 0; j < LEN_S; ++j) {
            char s = S[j];
            char t = T[i];
            if (s == t) {
                if (i == 0) {
                    dp[i][j] = 1;
                } else {
                    int r = j - 1;
                    while(r >= 0) {
                        if (dp[i - 1][r] > 0) {
                            dp[i][j] = j - r + dp[i - 1][r];
                            break;
                        }
                        --r;
                    }
                }
            }
        }
    }

    // Now we go to the last row and find the first match
    auto& lastRow = dp.back();
    int minPos = -1;
    int minLen = std::numeric_limits<int>::max();
    for(int i = 0; i < LEN_S; ++i) {
        if (lastRow[i] != 0 && lastRow[i] < minLen) {
            minPos = i;
            minLen = lastRow[i];
        }
    }

    if (minPos == -1) {
        return "";
    } else {
        return S.substr(minPos - minLen + 1, minLen);
    }
}
