#include <vector>

std::vector<std::vector<int>> removeInterval(
            std::vector<std::vector<int>>& intervals,
            std::vector<int>& toBeRemoved) {
    std::vector<std::vector<int>> result;

    const auto REMOVE_START = toBeRemoved[0];
    const auto REMOVE_END = toBeRemoved[1];

    for (auto interval: intervals) {
        const auto START = interval[0];
        const auto END = interval[1];

        if (END < REMOVE_START || START > REMOVE_END) {
            result.push_back(interval);
            continue;
        }

        if (START < REMOVE_START) {
            result.push_back(std::vector<int>{START, REMOVE_START});
        }
        if (END > REMOVE_END) {
            result.push_back(std::vector<int>{REMOVE_END, END});
        }
    }

    return result;
}
