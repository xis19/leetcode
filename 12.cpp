#include <string>
#include <vector>
#include <utility>

const std::vector<std::pair<int, std::string>> MAPPER = {
    std::make_pair(1000, "M"),
    std::make_pair(900, "CM"),
    std::make_pair(500, "D"),
    std::make_pair(400, "CD"),
    std::make_pair(100, "C"),
    std::make_pair(90, "XC"),
    std::make_pair(50, "L"),
    std::make_pair(40, "XL"),
    std::make_pair(10, "X"),
    std::make_pair(9, "IX"),
    std::make_pair(5, "V"),
    std::make_pair(4, "IV"),
    std::make_pair(1, "I")
};

std::string intToRoman(int num) {
   std::string result;
    for(auto kv : MAPPER) {
        while(num >= kv.first) {
            num -= kv.first;
            result += kv.second;
        }
    }
    return result;
}
