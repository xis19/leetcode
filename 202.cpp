#include <set>
bool isHappy(int n) {
    auto getValue = [&](int y) -> int {
        int sum = 0;
        while(y) {
            int v = y % 10;
            y /= 10;
            sum += v * v;
        }
        return sum;
    };
    std::set<int> values;

    while(true) {
        int newSum = getValue(n);
        if (values.find(newSum) != values.end()) {
            return false;
        }
        if (newSum == 1) {
            return true;
        }
        values.insert(newSum);
        n = newSum;
    }
}
