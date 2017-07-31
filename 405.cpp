#include <algorithm>
#include <string>

std::string toHex(int num) {
    if (num == 0) return std::string("0");

    std::string result;

    char chMapper[] = "0123456789abcdef";
    unsigned int mapping = 15;
    int shift = 0;
    while(num) {
        unsigned int v = num & mapping;
        v >>= shift;
        result += chMapper[v];
        num &= ~mapping;
        mapping <<= 4;
        shift += 4;
    }

    std::reverse(result.begin(), result.end());
    return result;
}
