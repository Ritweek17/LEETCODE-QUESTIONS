class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> count;

        for (int x : nums) {
            count[x]++;
        }

        for (int x : nums) {
            if (count[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};