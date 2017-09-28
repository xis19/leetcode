class Solution {
        const std::vector<int> m_original;
        std::vector<int> result;
    public:
        Solution(const std::vector<int>& nums) : m_original(nums), result(nums) {}

        std::vector<int> reset() {
            return m_original;
        }

        std::vector<int> shuffle() {
            // Random pick one, remove it from the list, repeat this procedure.
            std::random_device rd;
            std::mt19937 gen(rd());
            for(int i = m_original.size() - 1; i >= 2; --i) {
                std::swap(
                    result[i],
                    result[std::uniform_int_distribution<>(0, i)(gen)]
                );
            }
            return result;
        }
};
