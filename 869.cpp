#include <array>
#include <vector>

bool reorderedPowerOf2(int N) {
    static const std::vector<std::array<int, 10>> VALUES = {
        std::array<int, 10>{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        std::array<int, 10>{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        std::array<int, 10>{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        std::array<int, 10>{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        std::array<int, 10>{0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        std::array<int, 10>{0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        std::array<int, 10>{0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        std::array<int, 10>{0, 1, 1, 0, 0, 0, 0, 0, 1, 0},
        std::array<int, 10>{0, 0, 1, 0, 0, 1, 1, 0, 0, 0},
        std::array<int, 10>{0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
        std::array<int, 10>{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        std::array<int, 10>{1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
        std::array<int, 10>{1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
        std::array<int, 10>{0, 1, 1, 0, 0, 0, 0, 0, 1, 1},
        std::array<int, 10>{0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
        std::array<int, 10>{0, 0, 1, 1, 0, 0, 1, 1, 1, 0},
        std::array<int, 10>{0, 0, 0, 1, 0, 2, 2, 0, 0, 0},
        std::array<int, 10>{1, 2, 1, 1, 0, 0, 0, 1, 0, 0},
        std::array<int, 10>{0, 1, 2, 0, 2, 0, 1, 0, 0, 0},
        std::array<int, 10>{0, 0, 2, 0, 1, 1, 0, 0, 2, 0},
        std::array<int, 10>{1, 1, 0, 0, 1, 1, 1, 1, 1, 0},
        std::array<int, 10>{1, 1, 2, 0, 0, 1, 0, 1, 0, 1},
        std::array<int, 10>{1, 1, 0, 1, 3, 0, 0, 0, 0, 1},
        std::array<int, 10>{1, 0, 0, 1, 0, 0, 1, 0, 4, 0},
        std::array<int, 10>{0, 2, 1, 0, 0, 0, 2, 3, 0, 0},
        std::array<int, 10>{0, 0, 1, 3, 2, 2, 0, 0, 0, 0},
        std::array<int, 10>{1, 1, 0, 0, 1, 0, 2, 1, 2, 0},
        std::array<int, 10>{0, 2, 2, 1, 1, 0, 0, 2, 1, 0},
        std::array<int, 10>{0, 0, 1, 1, 2, 2, 2, 0, 1, 0},
        std::array<int, 10>{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        std::array<int, 10>{1, 2, 1, 1, 2, 0, 0, 2, 1, 0},
        std::array<int, 10>{0, 1, 1, 1, 3, 0, 1, 1, 2, 0}
    };

    std::array<int, 10> count;
    std::fill(count.begin(), count.end(), 0);
    while(N) {
        int mod = N % 10;
        ++count[mod];
        N /= 10;
    }

    for(auto v: VALUES) {
        if (v == count) {
            return true;
        }
    }
    return false;
}
