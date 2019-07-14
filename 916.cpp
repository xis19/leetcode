#include <algorithm>
#include <array>
#include <string>
#include <vector>

std::vector<std::string> wordSubsets(const std::vector<std::string>& A,
                                     const std::vector<std::string>& B) {
    // Since A has to be the superset of *every* element in B,
    // we construct the union of all strings in B
    typedef std::array<int, 26> counter;
    auto count = [](const std::string& s, counter& c) {
        std::fill(c.begin(), c.end(), 0);
        for (auto ch: s) ++c[ch - 'a'];
    };
    counter Bs;
    std::fill(Bs.begin(), Bs.end(), 0);
    for (const auto& b: B) {
        counter bc;
        count(b, bc);
        std::transform(Bs.begin(), Bs.end(), bc.begin(), Bs.begin(),
                       [](int a, int b) { return std::max(a, b); });
    }

    std::vector<std::string> result;
    for (const auto& a: A) {
        counter c;
        count(a, c);

        bool valid = true;
        for (char x = 0; x < 26; ++x) {
            if (c[x] < Bs[x]) {
                valid = false;
                break;
            }
        }
        if (valid) result.push_back(a);
    }

    return result;
}
