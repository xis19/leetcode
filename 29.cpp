#include <cmath>
#include <limits>

int divide(int dividend, int divisor) {
    int sign = std::copysign(1, dividend) * std::copysign(1, divisor);
    const long divisor_l(std::abs(static_cast<long>(divisor)));
    long quotient(0);
    long residue(std::abs(static_cast<long>(dividend)));

    while(residue >= divisor_l) {
        long div(divisor_l);
        long part(1);
        while(div < residue) {
            div <<= 1;
            part <<= 1;
        }
        if (div > residue) {
            div >>= 1;
            part >>= 1;
        }
        residue -= div;
        quotient += part;
    }

    quotient *= sign;
    if (quotient > std::numeric_limits<int>::max() || quotient < std::numeric_limits<int>::min()) {
        return std::numeric_limits<int>::max();
    }
    return quotient;
}
