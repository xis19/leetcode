#include <string>
#include <vector>


std::string removeDuplicates(const std::string& s, int k) {
    const size_t K = k;
    std::vector<int> stack;

    for (auto ch: s) {
        stack.push_back(ch);
        if (stack.size() < K) {
            continue;
        }
        bool allSame = true;
        for (auto i = 0; i < k; ++i) {
            if (stack[stack.size() - i - 1] != ch) {
                allSame = false;
                break;
            }
        }
        if (allSame) {
            for (auto i = 0; i < k; ++i) {
                stack.pop_back();
            }
        }
    }

    std::string t;
    std::copy(stack.begin(), stack.end(), std::back_inserter(t));
    return t;
}
