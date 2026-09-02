class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer = nums1;
        answer.insert(answer.end(), nums2.begin(), nums2.end());
        sort(answer.begin(), answer.end());
        int n = nums1.size()+nums2.size();
        if(n%2==0){
            int x = (n/2)-1;
            int y = (n/2);
            return (answer[x] + answer[y]) / 2.0;
        }else {
            return answer[n / 2];
        }
    }
};