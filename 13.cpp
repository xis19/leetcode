#include <map>
#include <string>
#include <utility>

const std::map<char, int> MAPPER = {
    std::make_pair('M', 1000),
    std::make_pair('D', 500),
    std::make_pair('C', 100),
    std::make_pair('L', 50),
    std::make_pair('X', 10),
    std::make_pair('V', 5),
    std::make_pair('I', 1)
};

int romanToInt(const std::string& s) {
    int result = 0;
    int lastVal = 0;
    for(auto ch : s) {
        int value = MAPPER.at(ch);
        if (value > lastVal)
            result += value - lastVal * 2;
        else
            result += value;
        lastVal = value;
    }
    return result;
}
