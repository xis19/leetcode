#include <algorithm>
#include <tuple>
#include <set>
#include <string>
#include <vector>


std::string originalDigits(const std::string& s) {
    // Some of the words has unique characters, e.g. foUr, siX, tWo.
    // We detect the character, remove them from string list.
    // When conflict, e.g. FiVe and seVen, notice that by removing foUr, F in
    // FiVe is unique.
    static const std::vector<std::tuple<char, std::string, char>> MAPPER = {
        std::make_tuple('z', "zero", '0'),
        std::make_tuple('x', "six", '6'),
        std::make_tuple('g', "eight", '8'),
        std::make_tuple('u', "four", '4'),
        std::make_tuple('w', "two", '2'),
        std::make_tuple('f', "five", '5'),
        std::make_tuple('v', "seven", '7'),
        std::make_tuple('h', "three", '3'),
        std::make_tuple('i', "nine", '9'),
        std::make_tuple('o', "one", '1'),
    };

    std::string result;
    std::multiset<char> chSet(s.begin(), s.end());
    for(auto& map: MAPPER) {
        while(chSet.find(std::get<0>(map)) != chSet.end()) {
            // erase cannot be used as it erases all ch existance... try
            // erase + lower_bound
            for(auto ch: std::get<1>(map)) chSet.erase(chSet.lower_bound(ch));
            result.push_back(std::get<2>(map));
        }
    }

    std::sort(result.begin(), result.end());
    return result;
}
