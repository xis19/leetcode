#include <string>

bool isLongPressedName(const std::string& name, const std::string& typed) {
    size_t nIter = 0;
    size_t tIter = 0;

    auto read = [](size_t& iter, const std::string& str) -> std::pair<char, int> {
        if (iter >= str.length()) {
            return std::make_pair('\0', 0);
        }

        char ch = str[iter++];
        int count = 1;
        while(iter < str.length() && str[iter] == ch) ++count, ++iter;

        return std::make_pair(ch, count);
    };

    auto fetchName = read(nIter, name);
    auto fetchTyped = read(tIter, typed);

    while(true) {
        if (fetchName.first == 0 && fetchTyped.first == 0) {
            return true;
        }
        if (fetchName.first != fetchTyped.first || fetchName.second > fetchTyped.second) {
            return false;
        }
        fetchName = read(nIter, name);
        fetchTyped = read(tIter, typed);
    }
}
