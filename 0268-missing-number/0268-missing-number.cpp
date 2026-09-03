class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> count(10001, 0);

        for (int x : nums) {
            count[x]++;
        }

        for (int i = 0; i <= nums.size(); i++) {
            if (count[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};