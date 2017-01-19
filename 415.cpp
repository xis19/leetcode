#include <string>

std::string addStrings(const std::string& num1, const std::string& num2) {
    std::string result;
    bool carry = false;

    std::string::const_reverse_iterator r1 = num1.rbegin();
    std::string::const_reverse_iterator r2 = num2.rbegin();

    const auto E1 = num1.rend();
    const auto E2 = num2.rend();

    while(!(r1 == E1 && r2 == E2)) {
        int sum = carry;
        if (r1 != E1) {
            sum += *r1++ - '0';
        }
        if (r2 != E2) {
            sum += *r2++ - '0';
        }
        carry = (sum >= 10);
        result.push_back(sum % 10 + '0');
    }
    if (carry) result.push_back('1');

    return std::string(result.rbegin(), result.rend());
}

