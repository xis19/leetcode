#include <algorithm>
#include <bitset>
#include <vector>

std::vector<int> prisonAfterNDaysSlow(std::vector<int>& cells, int N) {
    const int LEN = cells.size();

    for (int _ = 0; _ < N; ++_) {
        std::vector<int> currentState(cells.begin(), cells.end());
        cells.front() = 0;
        cells.back() = 0;
        for (int i = 1; i < LEN - 1; ++i) {
            cells[i] = !(currentState[i - 1] ^ currentState[i + 1]);
        }
    }

    return cells;
}


std::vector<int> prisonAfterNDays(std::vector<int>& cells, int N) {
    static const int LEN = 8;
    typedef std::bitset<LEN> state;

    auto stateToVec = [](const state& s) -> std::vector<int> {
        std::vector<int> result(LEN);
        for (int i = 0; i < LEN; ++i) {
            result[i] = s[i];
        }

        return result;
    };

    std::vector<state> history;

    {
        history.push_back(state());
        for(int i = 0; i < LEN; ++i) {
            history.back()[i] = cells[i];
        }
    }

    for (int _ = 0; _ < N; ++_) {
        state newState;
        newState[0] = 0;
        newState[LEN - 1] = 0;
        for (int i = 1; i < LEN - 1; ++i) {
            newState[i] = !(history.back()[i - 1] ^ history.back()[i + 1]);
        }

        for (int i = 0; i < static_cast<int>(history.size()); ++i) {
            if (history[i] == newState) {
                // Found a loop
                int length = history.size() - i;
                int remain = N - i;
                return stateToVec(history[(remain % length) + i]);
            }
        }

        history.emplace_back(newState);
    }

    return stateToVec(history.back());
}
