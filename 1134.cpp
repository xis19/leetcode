#include <cmath>
#include <sstream>
#include <string>

bool isArmstrong(int N) {
    std::stringstream ss;
    ss << N;

    std::string str;
    ss >> str;

    const int L = str.size();
    int sum = 0;
    for (auto s: str) {
        sum += std::pow(s - '0', L);
    }

    return sum == N;
}
