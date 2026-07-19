class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = ans << 1; // har it ans ko left shift tako nayi bit ke liye
                            // jagha ban jaye
            ans = ans | (n & 1); // cur bit ko or op, se ans me ad kar de ge
            n >>= 1;             // right shift the bit
        }
        return ans;
    }
};