#include <vector>

bool canWinNim0(int n) {
    if (n == 1 || n == 2 || n == 3) {
        return true;
    } else {
        return !(canWinNim0(n - 1) && canWinNim0(n - 2) && canWinNim0(n - 3));
    }
}

bool canWinNim1(int n) {
    std::vector<bool> canWin(std::max(n, 3));
    canWin[0] = true;
    canWin[1] = true;
    canWin[2] = true;

    for(int i = 3; i < n; ++i) {
        canWin[i] = !(canWin[i - 1] && canWin[i - 2] && canWin[i - 3]);
    }

    return canWin[n - 1];
}


bool canWinNim(int n) {
    return n % 4;
}

