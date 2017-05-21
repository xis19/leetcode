#include <iostream>
#include <string>
#include <limits>

int myAtoi(const std::string& str) {
    std::string::const_iterator iter = std::begin(str);
    int sign = 1;
    long result = 0;

    while(*iter == ' ' || *iter == '\t') ++iter;

    if (*iter == '+') {
        ++iter;
    } else if (*iter == '-') {
        ++iter;
        sign = -1;
    }

    for(;iter < std::end(str); ++iter) {
        if (!std::isdigit(*iter)) break;

        char num = *iter - '0';
        long new_result = (long(result * 10) + num);
        if (new_result * sign > std::numeric_limits<int>::max()) {
            return std::numeric_limits<int>::max();
        }
        if (new_result * sign < std::numeric_limits<int>::min()) {
            return std::numeric_limits<int>::min();
        }
        result = new_result;
    }
    return result * sign;
}

int main() {
    std::string i;
    while(std::cin >> i) {
        std::cout << myAtoi(i) << std::endl;
    }
}
