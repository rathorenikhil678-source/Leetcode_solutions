class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int newsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            int sum = 0;

            for (int j = 1; j <= nums[i]; j++) {

                if (nums[i] % j == 0) { //agar koi no fully divsible ho 
                    count++;
                    sum += j;
                }
                if (count > 4) { //agar count 4 se jyda ho jaye to break;
                    break;
                }
            }
            if (count == 4) {
                newsum += sum;
            }
        }
        return newsum;
    }
};