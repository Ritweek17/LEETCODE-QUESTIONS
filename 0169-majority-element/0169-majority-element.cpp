class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int count = 0;

        for (int x : nums) {
            if (count == 0) {
                element = x;
            }

            if (x == element) {
                count++;
            } else {
                count--;
            }
        }

        return element;
    }
};