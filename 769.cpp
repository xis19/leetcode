#include <vector>

int maxChunksToSorted(const std::vector<int>& arr) {
    // For, e.g.
    //  3 0 2 1 4
    // When we see 3, 3 is not a right position, and the chunk will at least in
    // range 0...3
    const int LEN = arr.size();
    int numChunks = 0;
    int maxChunkPos = 0;
    for (int i = 0; i < LEN; ++i) {
        const auto value = arr[i];
        if (maxChunkPos <= i && value == i) {
            // The value is sorted
            ++numChunks;
            continue;
        }

        if (value > i) {
            // we have to extent this chunk to at least value
            maxChunkPos = std::max(maxChunkPos, value);
            continue;
        }

        if (maxChunkPos == i) {
            // So far all number smaller than i is included in the chunk, start
            // a new chunk
            ++numChunks;
            continue;
        }
    }

    return numChunks;
}
