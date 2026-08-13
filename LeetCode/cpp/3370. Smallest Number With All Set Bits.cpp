class Solution {
public:
    // Bit Manipulation
    int smallestNumber(int n) {
        return (1 << std::bit_width((unsigned)n)) - 1;
    }
    // O(1) time, O(1) extra-space
};