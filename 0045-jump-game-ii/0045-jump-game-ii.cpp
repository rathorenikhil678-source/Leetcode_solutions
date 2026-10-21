
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0, r = 0;

        while (r < n - 1) {
            int farthest = 0; //sabse durr kitna ja sakta hu use curr ind ke liye

            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            jumps++;
            l = r + 1;
            r = farthest;
        }

        return jumps;
    }
};
