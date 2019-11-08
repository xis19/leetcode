#include <algorithm>
#include <string>
#include <vector>

std::vector<int> numSmallerByFrequency(const std::vector<std::string>& queries,
                                       const std::vector<std::string>& words) {
    auto f = [](const std::string& s) -> int {
        char minChar = 'z' + 1;
        int count = 0;
        for (auto ch: s) {
            if (ch < minChar) {
                minChar = ch;
                count = 0;
            }

            if (ch == minChar) {
                ++count;
            }
        }
        return count;
    };

    std::vector<int> wf;
    std::transform(words.begin(), words.end(), std::back_inserter(wf), f);
    std::sort(wf.begin(), wf.end());

    std::vector<int> result;
    for (auto& s: queries) {
        int k = f(s);
        auto smaller = std::lower_bound(wf.begin(), wf.end(), k);
        if (smaller == wf.begin() && k < *wf.begin()) {
            result.push_back(0);
        } else {
            auto larger = wf.end() - smaller - 1;
            result.push_back(larger);
        }
    }

    return result;
}
