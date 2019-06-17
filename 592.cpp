#include <cctype>
#include <sstream>
#include <string>
#include <utility>

std::string fractionAddition(const std::string& expression) {
    typedef decltype(expression.begin()) iterator_t;
    iterator_t iter = expression.begin();

    auto readToken = [&expression, &iter]() -> std::pair<int, int> {
        bool sgn = true;    // true for positive
        if (!std::isdigit(*iter)) {
            sgn = (*iter != '-');
            ++iter;
        }

        int nominator = 0;
        while(*iter != '/') {
            nominator *= 10;
            nominator += *iter - '0';
            ++iter;
        }

        ++iter;

        int denominator = 0;
        while(std::isdigit(*iter) && iter != expression.end()) {
            denominator = denominator * 10 + *iter - '0';
            ++iter;
        }

        return std::make_pair((sgn ? 1: -1) * nominator, denominator);
    };

    auto evaluate = [](const std::pair<int, int>& v1, const std::pair<int, int>& v2) -> std::pair<int, int> {
        return std::make_pair(v1.first * v2.second + v2.first * v1.second, v1.second * v2.second);
    };

    auto format = [](const std::pair<int, int>& v) -> std::string {
        std::stringstream ss;
        ss << v.first << '/' << v.second;
        return ss.str();
    };

    auto gcd = [](int i, int j) -> int {
        while(j != 0) {
            int tmp = j;
            j = i % j;
            i = tmp;
        }
        return i;
    };

    std::pair<int, int> value{0, 1};
    while(iter != expression.end()) {
        auto t = readToken();
        value = evaluate(value, t);
        int g = gcd(std::abs(value.first), std::abs(value.second));
        value = std::make_pair(value.first / g, value.second / g);
    }

    return format(value);
}
