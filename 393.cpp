#include <cstdlib>
#include <vector>

const int MASK_10000000 = 128;
const int MASK_11000000 = 128 + 64;
const int MASK_11100000 = 128 + 64 + 32;
const int MASK_11110000 = 128 + 64 + 32 + 16;
const int MASK_11111000 = 128 + 64 + 32 + 16 + 8;

bool validUtf8(std::vector<int>& data) {
    size_t N = data.size();
    size_t iter = 0;
    auto checkMultiBytes= [&](int nBytes) -> bool {
        if (iter + nBytes > N) return false;
        for(int i = 0; i < nBytes; ++iter, ++i) {
            int byte = data[iter];
            if ((byte & MASK_11000000) != MASK_10000000) return false;
        }
        return true;
    };
    auto checkData = [&]() -> bool {
        // End of data
        if (iter >= N) return true;

        int byte = data[iter++];
        if (byte < MASK_10000000) return true;

        if ((byte & MASK_11100000) == MASK_11000000) return checkMultiBytes(1);
        if ((byte & MASK_11110000) == MASK_11100000) return checkMultiBytes(2);
        if ((byte & MASK_11111000) == MASK_11110000) return checkMultiBytes(3);

        return false;
    };
    while(iter < N) {
        if (!checkData()) return false;
    }
    return true;
}


