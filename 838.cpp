#include <string>
#include <deque>

std::string pushDominoes(const std::string& dominoes) {
    const int LEN = dominoes.size();

    std::deque<std::pair<char, int>> states;
    for (size_t i = 0; i < dominoes.size(); ++i)
        if (dominoes[i] != '.')
            states.push_back(std::make_pair(dominoes[i], i));
    states.push_back({'R', LEN});

    std::string result(LEN, '.');

    while (states.size() > 1) {
        auto state = states.front();
        states.pop_front();
        if (state.first == 'L') {
            for (int i = state.second; i >= 0; --i) {
                if (result[i] != '.') break;
                result[i] = 'L';
            }
        } else {
            if (states.front().first != 'L') {
                for (int i = state.second; i < states.front().second; ++i) {
                    result[i] = 'R';
                }
            } else {
                for (int i = state.second, j = states.front().second; i < j; ++i, --j) {
                    result[i] = 'R';
                    result[j] = 'L';
                }
                states.pop_front();
            }
        }
    }

    return result;
}
