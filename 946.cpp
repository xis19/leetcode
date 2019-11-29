#include <functional>
#include <vector>

bool validateStackSequences(const std::vector<int>& pushed,
                            const std::vector<int>& popped) {
    std::function<bool(int, int, int, int)> validate = [&pushed, &popped, &validate](int pushedS, int pushedE, int poppedS, int poppedE) {
        int pushedI = pushedS, poppedI = poppedE;
        while (pushedI <= pushedE && pushed[pushedI] == popped[poppedI]) {
            ++pushedI;
            --poppedI;
        }
        if (pushedI > pushedE) {
            return true;
        }

        // We pushed sth that is not popped at last -- there must be some early
        // pop
        int finder = poppedI - 1;
        while (finder >= poppedS && popped[finder] != pushed[pushedI]) --finder;

        if (finder < poppedS) {
            return false;
        }

        return validate(pushedI + 1, pushedI + (finder - poppedS), poppedS, finder - 1) &&
            validate(pushedI + (finder - poppedS + 1), pushedE, finder + 1, poppedI);
    };

    const int LEN = pushed.size();
    if (pushed.size() != popped.size()) return false;
    return validate(0, LEN - 1, 0, LEN - 1);
}
