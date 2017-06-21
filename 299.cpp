#include <array>
#include <string>

std::string getHint(const std::string& secret, const std::string& guess) {
    const int LEN = secret.size();
    int bulls(0), cows(0);

    std::array<int, 10> sDigits, gDigits;
    std::fill(sDigits.begin(), sDigits.end(), 0);
    std::fill(gDigits.begin(), gDigits.end(), 0);

    for(int i = 0; i < LEN; ++i) {
        char ss = secret[i] - '0', gg = guess[i] - '0';
        if (ss == gg) {
            ++bulls;
        } else {
            sDigits[ss]++, gDigits[gg]++;
        }
    }

    for(int i = 0; i < 10; ++i) {
        cows += std::min(sDigits[i], gDigits[i]);
    }

    return std::to_string(bulls) + 'A' + std::to_string(cows) + 'B';
}
