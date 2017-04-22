#include <string>

std::string convertToBase7(int num) {
    if (!num) {
        return "0";
    }

    std::string result;
    bool neg = num < 0;

    if (neg) num = -num;
    while(num) {
        result.push_back(num % 7 + '0');
        num /= 7;
    }

    if (neg) {
        result = result + '-';
    }

    return std::string(result.rbegin(), result.rend());
}
