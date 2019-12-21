#include <bitset>
#include <functional>
#include <string>
#include <vector>

int maxLength(const std::vector<std::string>& arr) {
    typedef std::bitset<26> bitset;

    int longest = 0;
    bitset bs;
    bs.reset();

    std::vector<bitset> bitsets;
    for (auto& a: arr) {
        bitset bs;
        bool noDup = true;
        for (auto& ch: a) {
            if (bs.test(ch - 'a')) {
                noDup = false;
                break;
            }
            bs.set(ch - 'a');
        }
        if (noDup) {
            bitsets.emplace_back(bs);
        }
    }

    std::function<void(int)> backtrack = [&backtrack, &bitsets, &bs, &longest](int i) {
        if (i >= static_cast<int>(bitsets.size())) return;

        if ((bs & bitsets[i]).none()) {
            auto tmp = bs | bitsets[i];
            std::swap(tmp, bs);
            longest = std::max(static_cast<int>(bs.count()), longest);
            backtrack(i + 1);
            std::swap(tmp, bs);
        }
        backtrack(i + 1);
    };

    backtrack(0);

    return longest;
}
