#include <deque>
#include <vector>

void duplicateZeros(std::vector<int>& arr) {
    const int LEN = arr.size();

    std::deque<int> dq;
    for (int i = 0; i < LEN; ++i) {
        auto& v = arr[i];
        if (v == 0) {
            dq.push_back(0);
            dq.push_back(0);
        } else {
            dq.push_back(v);
        }
        v = dq.front();
        dq.pop_front();
    }
}
