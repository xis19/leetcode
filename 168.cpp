#include <algorithm>
#include <string>

std::string convertToTitle(int n) {
    std::string result;

    while(n) {
        int mod = n % 26;
        if (mod == 0)
            result += 'Z';
        else
            result += mod + 'A' - 1;
        n = (n - 1) / 26;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

#include <iostream>

int main() {
    for(int i = 1; i < 1000; ++i) {
        std::cout << i << '\t' << convertToTitle(i) << std::endl;
    }
    return 0;
}
