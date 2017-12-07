#include <vector>

class Vector2D {
    const std::vector<std::vector<int>>& vec;
    std::vector<std::vector<int>>::const_iterator vIter;
    std::vector<int>::const_iterator sIter;
    bool hasNextFlag;

private:
    void setSIter() {
        hasNextFlag = false;
        while(vIter != vec.cend()) {
            if (vIter->cbegin() == vIter->cend()) {
                ++vIter;
            } else {
                sIter = vIter->cbegin();
                hasNextFlag = true;
                break;
            }
        }
    }

public:
    Vector2D(const std::vector<std::vector<int>>& vec2d) :
            vec(vec2d), vIter(vec.cbegin()), hasNextFlag(false) {
        setSIter();
    }

    int next() {
        int result = *sIter++;

        if (sIter == vIter->cend()) {
            ++vIter;
            setSIter();
        }

        return result;
    }

    bool hasNext() {
        return hasNextFlag;
    }
};
