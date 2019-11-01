#include <string>

std::string strWithout3a3b(int A, int B) {
    // take the longest as 'a'
    bool swapAB = false;
    if (B > A) {
        std::swap(A, B);
        swapAB = true;
    }


    std::string result;
    // First fill ABABAB pattern
    //  three possibilities:
    //      A > B * 2 + 2, then there could not be a solution
    //      A > B * 2, then the result is AABAABAAB...BAA
    //      A = B * 2, then the result is AABAABAAB...AAB
    //      A < B * 2, then we could always write ABABAB until A = B * 2
    //              as (A - 1) - (B - 1) * 2 = (A - B * 2) + 1
    auto residue = A > B * 2 ? A - B * 2 : 0;
    A -= residue;

    // Fill ABAB pattern
    while(A < B * 2) {
        result.push_back('1');
        result.push_back('2');
        --A, --B;
    }

    // Then fill AABAAB pattern
    while(B > 0) {
        result.push_back('1');
        result.push_back('1');
        result.push_back('2');
        A -= 2;
        B -= 1;
    }

    for (auto i = 0; i < residue; ++i) {
        result.push_back('1');
    }

    char x = 'a', y = 'b';
    if (swapAB) std::swap(x, y);
    for (auto& ch: result) {
        if (ch == '1') ch = x; else ch = y;
    }

    return result;
}
