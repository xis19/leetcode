#include <string>
#include <unordered_set>
#include <vector>

std::vector<std::vector<std::string>> groupStrings(const std::vector<std::string>& strings) {
    // Be aware duplicated items in the incoming strings.
    std::unordered_multiset<std::string> stringSet(strings.begin(), strings.end());

    auto shift = [](std::string& s) {
        for(auto& ch: s) {
            ++ch;
            if (ch == 'z' + 1) {
                ch = 'a';
            }
        }
    };

    std::vector<std::vector<std::string>> result;
    while(!stringSet.empty()) {
        std::vector<std::string> items;
        auto s = *stringSet.begin();
        stringSet.erase(stringSet.begin());
        items.push_back(s);

        auto t = s;
        do {
            while(stringSet.find(t) != stringSet.end()) {
                stringSet.erase(stringSet.find(t));
                items.push_back(t);
            }
            shift(t);
        } while(t != s);

        result.emplace_back(items);
    }

    return result;
}
