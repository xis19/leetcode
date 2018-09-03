#include <algorithm>
#include <string>

std::string toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), [](char& ch) -> char{
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 'a' - 'A';
        }
        return ch;
    });
    return str;
}
