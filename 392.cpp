#include <string>

bool isSubsequence(const std::string& s, const std::string& t) {
    auto sIter = s.begin();
    auto tIter = t.begin();
    while(!(sIter == s.end() || tIter == t.end())) {
        if (*sIter == *tIter) {
            ++sIter, ++tIter;
        } else {
            ++tIter;
        }
    }
    return sIter == s.end();
}

// For the follow up question, consider make S as a tier
