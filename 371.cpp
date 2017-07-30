int getSum(int a, int b) {
    static const char VAL[] = {
        0, 1, 1, 0, 1, 0, 0, 1
    };
    static const char CARRY[] = {
        0, 0, 0, 1, 0, 1, 1, 1
    };
    unsigned int testBit = 1;
    int carry = 0;
    int result = 0;
    while(testBit) {
        int av = a & testBit, bv = b & testBit;
        int flag = ((int(bool(av))) << 2) | ((int(bool(bv))) << 1) | carry;
        if (VAL[flag])
            result |= testBit;
        carry = CARRY[flag];
        testBit <<= 1;
    }
    // carry would overflow, we don't care.
    return result;
}

