#include <string>

int lengthOfLastWord(const std::string& s) {
    int len = 0;
    auto iter = s.crbegin();
    while(iter != s.crend() && *iter == ' ') ++iter;
    while(iter != s.crend() && *iter++ != ' ') ++len;
    return len;
}
