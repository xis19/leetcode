#include <algorithm>
#include <list>
#include <vector>

class MyHashSet {
    const int MODULUS = 997;
    std::vector<std::list<int>> hash;
public:
    /** Initialize your data structure here. */
    MyHashSet(): hash(997, std::list<int>{}) {

    }

    void add(int key) {
        int modulus = key % MODULUS;
        if (std::find(hash[modulus].begin(), hash[modulus].end(), key) == hash[modulus].end()) {
            hash[modulus].push_back(key);
        }
    }

    void remove(int key) {
        int modulus = key % MODULUS;
        auto iter = std::find(hash[modulus].begin(), hash[modulus].end(), key);
        if (iter != hash[modulus].end()) {
            hash[modulus].erase(iter);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int modulus = key % MODULUS;
        auto iter = std::find(hash[modulus].begin(), hash[modulus].end(), key);
        return iter != hash[modulus].end();
    }
};
