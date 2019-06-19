#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

bool pyramidTransition(const std::string& bottom, const std::vector<std::string>& allowed) {
    std::unordered_map<char, std::unordered_map<char, std::string>> mapper;
    for(const auto& allow: allowed) {
        mapper[allow[0]][allow[1]].push_back(allow[2]);
    }

    std::function<bool(const std::string&)> recursive = [&mapper, &recursive](const std::string& bottom) -> bool {
        const int LEN = bottom.size();
        if (LEN == 1) {
            return true;
        }

        // Enumerate all possible choices
        std::vector<std::string> choices(0, "");

        char p = bottom[0];
        for (int i = 1; i < LEN; ++i) {
            char c = bottom[i];
            auto f1 = mapper.find(p);

            if (f1 == mapper.end()) {
                return false;
            }
            auto f2 = f1->second.find(c);
            if (f2 == f1->second.end()) {
                return false;
            }

            // Mulitple the choices by len(f2->second)
            const int LEN_OLD_CHOICES = choices.size();
            const int NUM_CHOICES = f2->second.size();
            choices.reserve(NUM_CHOICES * choices.size());
            for(int i = 1; i < NUM_CHOICES; ++i) {
                std::copy(choices.begin(), choices.begin() + LEN_OLD_CHOICES, std::back_inserter(choices));
            }

            // Construct all choices
            auto iter = choices.begin();
            for(auto ch: f2->second) {
                for(int i = 0; i < LEN_OLD_CHOICES; ++i, ++iter) {
                    iter->push_back(ch);
                }
            }

            p = c;
        }

        for(auto& choice: choices) {
            if (recursive(choice)) return true;
        }

        return false;
    };

    return recursive(bottom);
}
