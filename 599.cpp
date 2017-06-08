#include <limits>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::unordered_map<std::string, int> m1;
    for(int i = 0; i < static_cast<int>(list1.size()); ++i) {
        m1[list1[i]] = i;
    }

    std::vector<std::string> result;
    int minimal = std::numeric_limits<int>::max();
    for(int i = 0; i < static_cast<int>(list2.size()); ++i) {
        auto found = m1.find(list2[i]);
        if (found != m1.end()) {
            int index = i + found->second;
            if (index < minimal) {
                result.clear();
                minimal = index;
            }
            if (index == minimal) {
                result.push_back(list2[i]);
            }
        }
    }

    return result;
}
