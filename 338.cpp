#include <vector>

std::vector<int> countBits(int num) {
    std::vector<int> result(num + 1);   // extra 0 at beginning
    result[0] = 0;

    int z = 1;
    while((z << 1) <= num) {
        for(int i = 0; i < z; ++i) {
            result[i + z] = result[i] + 1;
        }

        z <<= 1;
    }
    for(int i = 0; z <= num; ++i, ++z) {
        result[z] = result[i] + 1;
    }

    return result;
}
