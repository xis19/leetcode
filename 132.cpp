#include <vector>
#include <string>

int minCut(const std::string& s) {
    // For a string with length x, the minimal cut is
    //   v[x] = min(v[x - 1] + 1, v[x - y] + 1...)
    // where y..x makes a palindrome
    const int LEN = s.size();
    // an empty string, or a 1 character string, needs no cut
    std::vector<int> v{-1, 0};
    for (int i = 1; i < LEN; ++i) {
        // The newcoming character is its own palindrome
        // note the index for v starts with 1
        int value = v[i + 1 - 1] + 1;

        // Now check for possible palindromes that includes the new character
        for (int j = i - 1; j >= 0; --j) {
            if (s[j] != s[i]) {
                continue;
            }

            // Check if palindrome
            int x = i, y = j;
            bool palindrome = true;
            while (x > y) {
                if (s[x] != s[y]) {
                    palindrome = false;
                    break;
                }
                --x, ++y;
            }
            if (palindrome) {
                // note v start index is 1
                // Also, if the palindrome starts with 0, then there is no cut
                // necessary
                value = std::min(j == 0 ? 0 : v[j + 1 - 1] + 1, value);
            }
        }

        v.push_back(value);
    }
    return v.back();
}
