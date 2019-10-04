#include <functional>
#include <vector>

std::vector<int> sortArray(std::vector<int>& nums) {
    typedef decltype(nums.begin()) iter_t;
    std::function<void(iter_t, iter_t)> sort = [&sort](iter_t i1, iter_t i2) {
        if (i1 >= i2) return;

        auto _i1 = i1, _i2 = i2;
        int pivot = *i1;
        while(i1 < i2) {
            while(*i2 >= pivot && i2 > i1) --i2;
            std::swap(*i1, *i2);
            while(*i1 <= pivot && i1 < i2) ++i1;
            std::swap(*i1, *i2);
        }

        // Note the pivot is already in the right position
        sort(_i1, std::prev(i1));
        sort(std::next(i2), _i2);
    };

    sort(nums.begin(), nums.end() - 1);

    return nums;
}
