// It can be easily solved using unordered set. Let's use dual vector
#include <numeric>
#include <vector>

class PhoneDirectory {
    std::vector<int> usedFlag;
    std::vector<int> unusedNumbers;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) : usedFlag(maxNumbers), unusedNumbers(maxNumbers) {
        std::fill(usedFlag.begin(), usedFlag.end(), 0);
        std::iota(unusedNumbers.begin(), unusedNumbers.end(), 0);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (unusedNumbers.empty()) {
            return -1;
        }
        int number = *unusedNumbers.begin();
        std::swap(unusedNumbers[0], unusedNumbers.back());
        unusedNumbers.pop_back();
        usedFlag[number] = 1;
        return number;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return !usedFlag[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (!check(number)) {
            usedFlag[number] = 0;
            unusedNumbers.push_back(number);
        }
    }
};
