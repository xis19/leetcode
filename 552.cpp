#include <cstdio>
#include <vector>

int checkRecord(int n) {
    static const long MODULUS = 1E9 + 7;

    // A: has A in the string
    // ATL1: has A, tailing one L
    // ATL2: has A, tailing two Ls
    // TL1: No A, tailing one L
    // TL2: No A, tailing two Ls
    // C: No A, no tailing Ls
    // B: Bad, has more than 1 A or more than 2 continuous Ls
    static std::vector<long> A, ATL1, ATL2, TL1, TL2, C, B;

    // States:
    // A: P->A L->ATL1 A->B
    // ATL1: P->A L->ATL2 A->B
    // ATL2: P->A L->B A->B
    // TL1: P->C L->TL2 A->A
    // TL2: P->C L->B A->A
    // C: P->C L->TL1 A->A
    // B: ATL->B

    if (A.size() == 0) {
        A.push_back(1);
        ATL1.push_back(0);
        ATL2.push_back(0);
        TL1.push_back(1);
        TL2.push_back(0);
        C.push_back(1);
        B.push_back(0);
    }

    // vector starts with 0
    size_t index = n - 1;
    if (index >= A.size()) {
        while(A.size() <= static_cast<size_t>(n)) {
            // Modulus law:
            // (a + b) mod C = (a mod C + b mod C) mod C
            long newA = A.back() + ATL1.back() + ATL2.back() + TL1.back() + TL2.back() + C.back();
            long newATL1 = A.back();
            long newATL2 = ATL1.back();
            long newTL1 = C.back();
            long newTL2 = TL1.back();
            long newC = C.back() + TL1.back() + TL2.back();
            long newB = A.back() + ATL1.back() + ATL2.back() + TL2.back() + 3 * B.back();

            A.push_back(newA % MODULUS);
            ATL1.push_back(newATL1 % MODULUS);
            ATL2.push_back(newATL2 % MODULUS);
            TL1.push_back(newTL1 % MODULUS);
            TL2.push_back(newTL2 % MODULUS);
            C.push_back(newC % MODULUS);
            B.push_back(newB % MODULUS);
        }
    }

    return (A[index] + ATL1[index] + ATL2[index] + TL1[index] + TL2[index] + C[index]) % MODULUS;
}

#include <iostream>

int main() {
    std::cout << checkRecord(1) << std::endl;
    std::cout << checkRecord(2) << std::endl;
    std::cout << checkRecord(3) << std::endl;
    std::cout << checkRecord(10000) << std::endl;
}
