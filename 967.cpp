#include <functional>
#include <string>
#include <vector>

std::vector<int> numsSameConsecDiff(int N, int K) {
    if (N == 1) {
        return std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    }

    std::vector<int> result;
    int current;
    std::function<void(int)> fill = [&result, &current, &fill, N, K](int index) {
        if (index == N) {
            result.push_back(current);
            return;
        }

        int x = current % 10;
        if (x + K < 10) {
            int tmp = current;
            current = current * 10 + x + K;
            fill(index + 1);
            current = tmp;
        }
        // Corner case, K = 0, then the two branches are the same
        if (x - K >= 0 && K != 0) {
            int tmp = current;
            current = current * 10 + x - K;
            fill(index + 1);
            current = tmp;
        }
    };

    for (int i = 1; i < 10; ++i) {
        current = i;
        fill(1);
    }

    return result;
}
