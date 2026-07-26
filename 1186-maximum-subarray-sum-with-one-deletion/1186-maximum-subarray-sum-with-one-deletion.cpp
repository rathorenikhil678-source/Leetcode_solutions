class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1){
            return arr[0];
        }
        vector<int> lm(n);
        vector<int> rm(n);
        int ans = arr[0];
        lm[0] = arr[0];
        for (int i = 1; i < n; i++) {
            lm[i] = max(arr[i], arr[i] + lm[i - 1]);
            ans = max(ans, lm[i]);
        }
        rm[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rm[i] = max(arr[i], arr[i] + rm[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, lm[i - 1] + rm[i + 1]);
        }
        return ans;
    }
};