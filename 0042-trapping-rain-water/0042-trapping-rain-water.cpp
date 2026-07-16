class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);

        lmax[0] = height[0];         // LEFT MAX YANI AGE SE
        rmax[n - 1] = height[n - 1]; // RIGHT MAX YANI PICHE SE

        // sabse pehle left max nikalo
        for (int i = 1; i < n; i++) {
            lmax[i] = max(lmax[i - 1], height[i]);
        }

        // fir right max nikLO
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(rmax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) { // LEFT OR RIGHT MAX ME DONO ME CHOTA NO
                                      // HAI USE MINUS KARDO HRIGHT SE
            ans += min(lmax[i], rmax[i]) - height[i];
        }
        return ans;
    }
};