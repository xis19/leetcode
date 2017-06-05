#include <algorithm>
#include <string>

std::string mulitply(std::string s1, std::string s2) {
    if (s1.length() > s2.length()) std::swap(s1, s2);
    std::reverse(std::begin(s1), std::end(s1));
    std::reverse(std::begin(s2), std::end(s2));

    std::string result("0");
    result.reserve(s1.length() + s2.length());

    int zeros = 0;
    for(auto ch1: s1) {
        if (ch1 == '0') {
            ++zeros;
            continue;
        }

        std::string u;
        u.reserve(zeros + s2.length() + 1);

        for(int i = 0; i < zeros; ++i) {
            u.push_back('0');
        }
        ++zeros;

        int carry = 0;
        for(auto ch2: s2) {
            int product = (ch1 - '0') * (ch2 - '0') + carry;
            u.push_back(product % 10 + '0');
            carry = 0;
            if (product >= 10) {
                carry = product / 10;
            }
        }
        if (carry) u.push_back('0' + carry);

        std::swap(u, result);
        carry = 0;
        for(size_t i = 0; i < result.length(); ++i) {
            int value = result[i] - '0' + (u.length() > i ? u[i] - '0' : 0) + carry;
            result[i] = value % 10 + '0';
            carry = value >= 10 ? 1 : 0;
        }
        if (carry) result.push_back('0' + carry);
    }

    std::reverse(std::begin(result), std::end(result));

    return result;
}

#include <iostream>
#include <sstream>

int main() {
    std::string s1, s2;
    std::cin >> s1;
    std::cin >> s2;

    std::cout << mulitply(s1, s2) << std::endl;

    return 0;
}
