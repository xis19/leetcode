#include <list>
#include <unordered_map>


class LRUCache {
    typedef std::list<std::pair<int, int>> value_container_t;
    typedef value_container_t::iterator value_container_iter_t;
    value_container_t valueList;
    std::unordered_map<int, value_container_iter_t> valueMapper;
    const int capacity;
public:
    LRUCache(int _capacity) : capacity(_capacity) {
    }

    int get(int key) {
        auto f = valueMapper.find(key);
        if (f == valueMapper.end())
            return -1;
        auto v = *(f->second);
        valueList.erase(f->second);
        valueList.push_front(v);
        valueMapper[key] = valueList.begin();
        return f->second->second;
    }

    void put(int key, int value) {
        if (get(key) == -1) {
            valueList.push_front(std::make_pair(key, value));
            valueMapper[key] = valueList.begin();
        } else {
            auto item = *valueMapper[key];
            item.second = value;
            valueList.erase(valueMapper[key]);
            valueList.push_front(item);
            valueMapper[key] = valueList.begin();
        }
        while(static_cast<int>(valueList.size()) > capacity) {
            int key = valueList.back().first;
            valueList.pop_back();
            valueMapper.erase(key);
        }
    }
};
