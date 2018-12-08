#include <vector>

bool validMountainArray(const std::vector<int>& A) {
    const int LEN = A.size();
    if (LEN < 3) return false;

    int flag = 0;

    int prev = A[0];
    for(int i = 1; i < LEN; ++i) {
        int curr = A[i];
        int diff = curr - prev;

        if (flag == 0) {
            if (diff > 0) {
                flag = 1;
            } else {
                return false;
            }
        } else if (flag == 1) {
            if (diff < 0) {
                flag = -1;
            } else if (diff == 0) {
                return false;
            }
        } else if (flag == -1) {
            if (diff >= 0) {
                return false;
            }
        }

        prev = curr;
    }

    return flag < 0;
}
