#include <algorithm>
#include <string>

std::string addBinary(const std::string& a, const std::string& b) {
    int carry = 0;
    auto rA = a.rbegin(), rB = b.rbegin();
    std::string result = "";

    bool done(true);
    do {
        int da(0), db(0);
        done = true;
        if (rA != a.rend()) {
            da = *rA++ - '0';
            done = false;
        }
        if (rB != b.rend()) {
            db = *rB++ - '0';
            done = false;
        }

        if (!done) {
            int v = da + db + carry;
            result.push_back('0' + v % 2);
            carry = v / 2;
        }

    } while(!done);
    if (carry) result.push_back('1');
    std::reverse(result.begin(), result.end());
    return result;
}
