#include <array>
#include <vector>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    const int DIM = 9;
    std::array<int, DIM> rF;
    std::fill(rF.begin(), rF.end(), 0);
    std::array<int, DIM> cF;
    std::fill(cF.begin(), cF.end(), 0);
    std::array<int, DIM> bF;
    std::fill(bF.begin(), bF.end(), 0);

    for(int r = 0; r < DIM; ++r) {
        for(int c = 0; c < DIM; ++c) {
            char ch = board[r][c];
            if (ch == '.') continue;
            int val = 1 << (ch - '0');
            int b = r / 3 * 3 + c / 3;
            if ((rF[r] & val) || (cF[c] & val) || (bF[b] & val)) return false;
            rF[r] |= val;
            cF[c] |= val;
            bF[b] |= val;
        }
    }
    return true;
}
