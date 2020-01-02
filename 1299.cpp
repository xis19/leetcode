#include <vector>

std::vector<int> replaceElements(std::vector<int>& arr) {
    int last = -1;
    for (auto riter = arr.rbegin(); riter != arr.rend(); ++riter) {
        if (*riter > last) {
            std::swap(*riter, last);
        } else {
            *riter = last;
        }
    }
    return arr;
}
