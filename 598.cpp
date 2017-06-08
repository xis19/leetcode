#include <limits>
#include <vector>

int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
    int I = m, J = n;

    for(auto& op: ops) {
        int i = op[0], j = op[1];
        I = std::min(I, i);
        J = std::min(J, j);
    }

    return I * J;
}
