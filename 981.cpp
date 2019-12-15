#include <map>
#include <string>
#include <unordered_map>

class TimeMap {
    std::unordered_map<std::string,
        std::map<int, std::string>> record;
public:
    /** Initialize your data structure here. */
    TimeMap() {}

    void set(const std::string& key, const std::string& value, int timestamp) {
        record[key][timestamp] = value;
    }

    std::string get(const std::string& key, int timestamp) {
        auto& map = record[key];
        auto iter = map.upper_bound(timestamp);
        if (iter == map.begin()) {
            return "";
        }
        return std::prev(iter)->second;
    }
};

