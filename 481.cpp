#include <string>
#include <iostream>

int magicalString(int n) {
    if (n == 0) return 0;
    std::string magical{true, false, false};
    int num1s = 1;
    int countIter = 3;
    int generateIter = 2;
    bool flagValue = true;

    while(countIter < n) {
        bool numGenerateValues = magical[generateIter++];
        magical.push_back(flagValue);
        ++countIter;
        num1s += flagValue;
        if (countIter >= n) break;
        if (numGenerateValues == false) { // false --> 2
            ++countIter;
            num1s += flagValue;
            magical.push_back(flagValue);
        }
        flagValue = !flagValue;
    }

    for(auto i: magical) {
        if (i) std::cout<<1; else std::cout<<2;
    }
    std::cout<<std::endl;
    return num1s;
}

int main() { magicalString(1000); }
