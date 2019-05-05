#include <cctype>
#include <vector>

int numRookCaptures(const std::vector<std::vector<char>>& board) {
    const int BOARD_SIZE = 8;
    // Locate the rook
    int rr(0), rc(0);
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 'R') {
                rr = i;
                rc = j;
                goto found;
            }
        }
    }
    return 0;

found:
    int capture = 0;
    auto verifyCurrentStone = [&capture, &board](int i, int j) -> bool {
        if (board[i][j] != '.') {
            if (std::islower(board[i][j])) {
                ++capture;
            }
            return true;
        }
        return false;
    };

    for (int i = rr - 1; i >= 0; --i)
        if (verifyCurrentStone(i, rc)) break;

    for (int i = rr + 1; i < BOARD_SIZE; ++i)
        if (verifyCurrentStone(i, rc)) break;

    for (int i = rc - 1; i >= 0; --i)
        if (verifyCurrentStone(rr, i)) break;

    for (int i = rc + 1; i < BOARD_SIZE; ++i)
        if (verifyCurrentStone(rr, i)) break;

    return capture;
}
