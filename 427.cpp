#include <functional>
#include <vector>

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node* construct(const std::vector<std::vector<int>>& grid) {
    const int SIZE = grid.size();
    std::function<Node*(int, int, int, int)> traverser = [&](int l, int t, int r, int b) -> Node* {
        const int PARTITION_SIZE = r - l + 1;
        int numOnes = 0;
        for(int y = t; y <= b; ++y) {
            for(int x = l; x <= r; ++x) {
                if (grid[y][x]) ++numOnes;
            }
        }

        if (numOnes == PARTITION_SIZE * PARTITION_SIZE) {
            // This is a full 1
            return new Node(true, true, nullptr, nullptr, nullptr, nullptr);
        } else if (numOnes == 0) {
            // This is a full 0
            return new Node(false, true, nullptr, nullptr, nullptr, nullptr);
        }

        Node* result = new Node(false, false, nullptr, nullptr, nullptr, nullptr);
        result->topLeft = traverser(l, t, l + PARTITION_SIZE / 2 - 1, t + PARTITION_SIZE / 2 - 1);
        result->topRight = traverser(l + PARTITION_SIZE / 2, t, r, t + PARTITION_SIZE / 2 - 1);
        result->bottomLeft = traverser(l, t + PARTITION_SIZE / 2, l + PARTITION_SIZE / 2 - 1, b);
        result->bottomRight = traverser(l + PARTITION_SIZE / 2, t + PARTITION_SIZE / 2, r, b);

        return result;
    };
    return traverser(0, 0, SIZE - 1, SIZE - 1);
}
