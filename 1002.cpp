#include <algorithm>
#include <set>
#include <string>
#include <vector>


std::vector<std::string> commonChars(const std::vector<std::string>& A) {
    const int LEN = A.size();
    std::vector<std::string> result;
    if (LEN == 0) return result;

    std::multiset<std::string> ms;
    for(const char ch: A[0]) {
        ms.insert(std::string(1, ch));
    }

    for(int i = 1; i < LEN; ++i) {
        const std::string& s = A[i];
        std::multiset<std::string> ms1;
        for(const char ch: s) {
            ms1.insert(std::string(1, ch));
        }

        std::multiset<std::string> intersect;
        // We could not use back_inserter since multiset does not support
        // push_back
        std::set_intersection(ms.begin(), ms.end(), ms1.begin(), ms1.end(), std::inserter(intersect, intersect.begin()));

        std::swap(intersect, ms);
    }

    return std::vector<std::string>(ms.begin(), ms.end());
}

