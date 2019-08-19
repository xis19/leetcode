#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class RandomizedCollection {
    // We use a vector to store all the values, and use an unordered_map to
    // check if a value exists or not. The value of unordered_map implies the
    // number of duplicates of the values.
    std::vector<int> m_container;
    std::unordered_map<int, std::unordered_set<int>> m_indexMapper;

    std::default_random_engine generator;
    std::uniform_int_distribution<> distribution;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m_container.push_back(val);
        m_indexMapper[val].insert(m_container.size() - 1);

        return m_indexMapper[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m_indexMapper.find(val) == m_indexMapper.end()) {
            return false;
        }

        int backIndex = m_container.size() - 1;
        if (m_container.back() == val) {
            m_indexMapper[val].erase(backIndex);
        } else {
            int valIndex = *m_indexMapper[val].begin();
            m_indexMapper[val].erase(valIndex);

            int back = m_container.back();
            m_indexMapper[back].erase(backIndex);
            m_indexMapper[back].insert(valIndex);
            m_container[valIndex] = back;
        }

        m_container.pop_back();
        if (m_indexMapper[val].size() == 0) {
            m_indexMapper.erase(val);
        }
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        decltype(distribution.param()) range(0, m_container.size() - 1);
        distribution.param(range);
        return m_container[distribution(generator)];
    }
};

