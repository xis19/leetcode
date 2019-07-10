#include <string>

std::string defangIPaddr(const std::string& address) {
    std::string result;
    for(auto ch: address) {
        if (ch == '.') result += "[.]";
        else result.push_back(ch);
    }
    return result;
}
