#include <cmath>
#include <vector>

int countPrimes_Slow(int n) {
    if (n < 2) return 0;

    std::vector<int> knownPrimes(0);
    for(int i = 2; i < n; ++i) {
        bool isPrime = true;
        for(auto c: knownPrimes) {
            if (i % c == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            knownPrimes.push_back(i);
        }
    }

    return knownPrimes.size();
}

int countPrimes(int n) {
    const int SQRT_N = std::sqrt(n);
    if (n < 2) return 0;

    std::vector<bool> primes(n, true);
    primes[0] = false;
    primes[1] = false;
    for(int i = 2; i <= SQRT_N; ++i) {
        if (!primes[i]) continue;
        for(int j = i + i; j < n; j += i) {
            primes[j] = false;
        }
    }

    int count = 0;
    for(auto i: primes) count += i;
    return count;
}
