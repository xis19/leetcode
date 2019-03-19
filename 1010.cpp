#include <unordered_map>
#include <vector>

int numPairsDivisibleBy60(std::vector<int>& time) {
    int sum = 0;

    // We could do an O(n^2) search, but since we are looking for divisible by
    // 60, (a + b) % 60 == 0 -> a % 60 + b % 60 == 60
    std::unordered_map<int, int> modulus;
    for(auto v: time) {
        int mod = v % 60;
        // Corner case! v == 60, target must be 0
        int target = (60 - mod) % 60;

        if (modulus.find(target) != modulus.end()) {
            sum += modulus[target];
        }

        if (modulus.find(mod) == modulus.end()) {
            modulus[mod] = 0;
        }
        ++modulus[mod];
    }

    return sum;
}
