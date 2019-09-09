#include <algorithm>
#include <stdexcept>
#include <string>

bool counfusingNumber(int N) {
    std::string s(std::to_string(N));
    std::string output;
    output.resize(s.size());

    try {
        std::transform(s.begin(), s.end(), output.begin(), [](char ch) {
            if (ch == '0') return '0';
            if (ch == '1') return '1';
            if (ch == '6') return '9';
            if (ch == '8') return '8';
            if (ch == '9') return '6';
            throw std::runtime_error("");
        });
        std::reverse(output.begin(), output.end());
        return s != output;
    }
    catch (std::runtime_error& ex) {
        return false;
    }
}
