#include <set>

int countPrimeSetBits(int L, int R) {
    int count(0);
    std::set<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for(int i = L; i <= R; ++i) {
        int sCount(0);
        int v = i;
        while(v) {
            sCount += v & 1;
            v >>= 1;
        }
        if (primes.find(sCount) != primes.end())
            ++count;
    }
    return count;
}
