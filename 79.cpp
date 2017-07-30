#include <array>
#include <functional>
#include <set>
#include <string>
#include <utility>
#include <vector>


bool exist(const std::vector<std::vector<char>>& board, const std::string& word) {
    const int M = board.size();
    if (M == 0) return false;
    const int N = board[0].size();
    if (N == 0) return false;
    const int WORDLEN = word.length();
    if (!WORDLEN) return 0;

    std::set<int> visited;
    std::function<bool(int, int, int)> tryMatch = [M, N, WORDLEN, &visited, &tryMatch, &board, &word](int i, int j, int iter) -> bool {
        if (iter == WORDLEN - 1) return true;

        visited.insert(i * N + j);

        std::array<std::pair<int, int>, 4> potentialDirections = {{
            std::make_pair(i - 1, j),
            std::make_pair(i, j - 1),
            std::make_pair(i + 1, j),
            std::make_pair(i, j + 1)
        }};
        char nextChar = word[iter + 1];

        for(auto& dirs: potentialDirections) {
            if (visited.find(dirs.first * N + dirs.second) == visited.end() &&
                    dirs.first >= 0 && dirs.first < M &&
                    dirs.second >= 0 && dirs.second < N) {
                if (board[dirs.first][dirs.second] == nextChar &&
                        tryMatch(dirs.first, dirs.second, iter + 1))
                    return true;
            }
        }

        visited.erase(i * N + j);
        return false;
    };

    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if (board[i][j] == word[0] && (visited.clear(), tryMatch(i, j, 0)))
                return true;
        }
    }
    return false;
}
