class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int pos = -1;

        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
                pos = i;
            }
        }

        if (count > 1)
            return -1;

        if (count == 0)
            return 0;

    
        return n - pos - 1;
    }
};