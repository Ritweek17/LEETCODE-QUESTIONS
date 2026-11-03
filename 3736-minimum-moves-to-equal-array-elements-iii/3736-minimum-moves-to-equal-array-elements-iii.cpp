class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0 ;
        int n = nums.size();
        for(int i = 0 ; i < n-1 ;i++){
            count+= (nums[n-1]-nums[i]);
        }
        return count ;
        
    }
};