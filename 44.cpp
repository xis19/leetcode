#include <iostream>
#include <functional>
#include <string>

bool isMatch_Slow(std::string s, std::string p) {
    typedef std::string::const_iterator SCIter;
    const auto SEND = std::end(s);
    const auto PEND = std::end(p);
    std::function<bool(SCIter, SCIter)> visitor = [&](SCIter sI, SCIter sP) {
        if (sI == SEND && sP == PEND) {
            return true;
        } else if (sI == SEND) {
            // NOTE "" matches "*"
            if (*sP == '*') {
                return visitor(sI, std::next(sP));
            } else {
                return false;
            }
        } else if (sP == PEND) {
            return false;
        }

        char ss = *sI, pp = *sP;
        if (pp != '?' && pp != '*') {
            if (ss != pp) {
                return false;
            } else {
                return visitor(std::next(sI), std::next(sP));
            }
        } else if (pp == '?') {
            return visitor(std::next(sI), std::next(sP));
        } else {
            // pp == '*'
            return visitor(std::next(sI), sP) ||
                   visitor(std::next(sI), std::next(sP)) ||
                   visitor(sI, std::next(sP));
        }
    };

    return visitor(std::begin(s), std::begin(p));
}

#include <vector>
bool isMatch(std::string s, std::string p) {
    const int LEN_S = s.size();
    const int LEN_P = p.size();
    std::vector<std::vector<int>> dp(LEN_P + 1, std::vector<int>(LEN_S + 1, 0));

    std::cout << "S " << s << "\tP " << p << std::endl;

    // An empty pattern may not match any non-empty string
    std::fill(dp[0].begin(), dp[0].end(), 0);
    dp[0][0] = 1;

    // An empty string may only match to a single '*' at the very beginning
    for(int i = 1; i <= LEN_P; ++i) {
        dp[i][0] = (p[i - 1] == '*' && dp[i - 1][0] == 1);
    }

    for(int i = 1; i <= LEN_P; ++i) {
        for(int j = 1; j <= LEN_S; ++j) {
            char P = p[i - 1];
            char S = s[j - 1];

            if (S == P || P == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (P == '*') {
                // assume no match found
                dp[i][j] = 0;

                int r = j;
                while(r >= 0) {
                    // If the pattern prior to * matches any string [0..j]
                    if (dp[i - 1][r] == 1) {
                        dp[i][j] = 1;
                        break;
                    }
                    --r;
                }
            }
        }
    }
    for(int i = 0; i <= LEN_P; ++i) {
        for(int j = 0; j <= LEN_S; ++j) {
            std::cout<<dp[i][j]<<' ';
        }
        std::cout<<std::endl;
    }

    return dp.back().back() == 1;
}
