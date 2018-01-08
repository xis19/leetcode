#include <vector>

void gameOfLife(std::vector<std::vector<int>>& board) {
    const int RR = board.size();
    if (RR == 0) return;
    const int CC = board[0].size();
    if (CC == 0) return;

    // use the higher bit to store information
    const int DIE = 1 << 6;
    const int BORN = 1 << 7;


    auto countNeighbor = [&board, RR, CC](int i, int j) -> int {
        int count = 0;
        for(int ii = -1; ii <= 1; ++ii) {
            int ia = i + ii;
            if (ia < 0 || ia >= RR) continue;
            for(int jj = -1; jj <= 1; ++jj) {
                int ja = j + jj;
                if (ja < 0 || ja >= CC) continue;
                count += board[ia][ja] & 1;
            }
        }
        count -= board[i][j] & 1;
        return count;
    };

    for(int i = 0; i < RR; ++i) {
        for(int j = 0; j < CC; ++j) {
            int nb = countNeighbor(i, j);
            if (board[i][j] == 0) {
                if (nb == 3)
                    board[i][j] |= BORN;
                else
                    board[i][j] |= DIE;
            } else {
                if (nb < 2)
                    board[i][j] |= DIE;
                else if (nb == 2 || nb == 3)
                    board[i][j] |= BORN;
                else if (nb > 3)
                    board[i][j] |= DIE;
            }
        }
    }

    for(int i = 0; i < RR; ++i)
        for(int j = 0; j < CC; ++j)
            if (board[i][j] & BORN)
                board[i][j] = 1;
            else
                board[i][j] = 0;
}
