#include <random>
#include <vector>
#include <unordered_map>

class RandomizedSet {
    std::mt19937_64 mtRand;
    std::unordered_map<int, int> mapper;
    std::vector<int> values;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mapper.find(val) != mapper.end()) {
            return false;
        }
        values.push_back(val);
        mapper[val] = values.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mapper.find(val) == mapper.end()) {
            return false;
        }

        // We move the last element to the dropped element, this avoids the move
        // of all elements after the element deleted.
        auto last = values.back();
        mapper[last] = mapper[val];
        values[mapper[val]] = last;

        values.pop_back();
        mapper.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return values[mtRand() % values.size()];
    }
};
