#include <vector>

std::vector<int> arraysIntersection(const std::vector<int>& arr1,
                                    const std::vector<int>& arr2,
                                    const std::vector<int>& arr3) {
    std::vector<int> result;
    auto i1 = arr1.begin();
    auto i2 = arr2.begin();
    auto i3 = arr3.begin();
    while(i1 != arr1.end() && i2 != arr2.end() && i3 != arr3.end()) {
        if (*i1 == *i2 && *i2 == *i3) {
            result.push_back(*i1);
            ++i1;
        } else {
            int min = *i1;
            auto* pMinIter = &i1;

            if (*i2 < min) {
                min = *i2;
                pMinIter = &i2;
            }

            if (*i3 < min) {
                min = *i3;
                pMinIter = &i3;
            }

            ++*pMinIter;
        }
    }

    return result;
}
