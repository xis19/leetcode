#include <algorithm>
#include <limits>
#include <vector>

class Top3 {
    std::vector<int> values;
public:
    Top3() {
    }

    void push(int value) {
        bool inserted = false;
        for(auto i = values.begin();i < values.end(); ++i) {
            if (*i < value) {
                values.insert(i, value);
                inserted = true;
                break;
            } else if (*i == value) {
                return;
            }
        }

        if (values.size() > 3) {
            values.pop_back();
        } else if (values.size() < 3 && !inserted) {
            values.push_back(value);
        }
    }

    int result() {
        if (values.size() < 3) {
            return values.front();
        } else {
            return values.back();
        }
    }
};

int thirdMax(const std::vector<int>& nums) {
    Top3 t3;
    for(auto i: nums) {
        t3.push(i);
    }
    return t3.result();
}
