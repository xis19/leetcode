#include <algorithm>
#include <unordered_map>
#include <vector>

int largestValsFromLabels(const std::vector<int>& values,
                          const std::vector<int>& labels,
                          int num_wanted, int use_limit) {
    const int LEN = values.size();
    std::vector<std::pair<int, int>> sortedValues;
    for (int i = 0; i < LEN; ++i) {
        sortedValues.push_back(std::make_pair(values[i], labels[i]));
    }
    std::sort(sortedValues.begin(), sortedValues.end(),
              [](const std::pair<int, int>& _1, const std::pair<int, int>& _2) {
                return _1.first > _2.first;
              });

    std::unordered_map<int, int> labelCount;
    int sum(0);
    for (const auto& elem: sortedValues) {
        if (num_wanted == 0) break;

        const auto VALUE = elem.first;
        const auto LABEL = elem.second;
        if (labelCount.find(LABEL) == labelCount.end()) {
            labelCount[LABEL] = 0;
        }
        if (labelCount[LABEL] < use_limit) {
            ++labelCount[LABEL];
            sum += VALUE;
            --num_wanted;
        }
    }

    return sum;
}
