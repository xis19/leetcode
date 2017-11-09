#include <algorithm>
#include <functional>
#include <tuple>
#include <utility>
#include <vector>


int kthSmallest(const std::vector<std::vector<int>>& matrix, const int k) {
    const int DIM = matrix.size();
    typedef std::tuple<int, int, int> heapElement;
    auto heapElementCompare = [](const heapElement& e1, const heapElement& e2) -> bool {
        return std::get<0>(e1) >=  std::get<0>(e2);
    };

    std::vector<heapElement> heap;
    for(int i = 0; i < DIM; ++i)
        heap.push_back(std::make_tuple(matrix[i][0], i, 0));
    std::make_heap(heap.begin(), heap.end(), heapElementCompare);

    for(int i = 0; i < k - 1; ++i) {
        std::pop_heap(heap.begin(), heap.end(), heapElementCompare);
        auto element = heap.back();
        heap.pop_back();

        auto row = std::get<1>(element);
        auto index = std::get<2>(element);
        if (index < DIM - 1) {
            ++index;
            heap.push_back(std::make_tuple(matrix[row][index], row, index));
            std::push_heap(heap.begin(), heap.end(), heapElementCompare);
        }
    }

    std::pop_heap(heap.begin(), heap.end(), heapElementCompare);
    return std::get<0>(heap.back());
}
