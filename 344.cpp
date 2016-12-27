#include <algorithm>
#include <iterator>
#include <string>

std::string reverseString(std::string s) {
    std::string result;
    std::copy(s.rbegin(), s.rend(), std::back_inserter(result));
    return result;
}
