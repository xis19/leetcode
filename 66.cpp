#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int carry(0);

    auto i = digits.rbegin();
    *i = *i + 1;
    carry = *i / 10;
    *i %= 10;
    ++i;

    for(;i != digits.rend(); ++i) {
        if (!carry) break;
        *i = *i + carry;
        carry = *i / 10;
        *i %= 10;
    }
    if (carry) digits.insert(digits.begin(), 1);

    return digits;
}
