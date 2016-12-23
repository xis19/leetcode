#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.size() == 0)
        return std::string();

    size_t len = strs[0].length();
    for(size_t i = 1; i < strs.size(); ++i) {
        size_t j = 0;
        for(; j < std::min(len, strs[i].length()); ++j) {
            if (strs[0][j] != strs[i][j])
                break;
        }
        len = j;
    }

    return strs[0].substr(0, len);
}
