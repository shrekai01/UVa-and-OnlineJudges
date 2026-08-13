class Solution {
public:
    // Bit Manipulation
    int countMonobit(int n) {
        return bit_width((unsigned)n + 1);
    }
    // O(1) time, O(1) extra-space
};