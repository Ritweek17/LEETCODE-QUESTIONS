class Solution {
public:
    int numberOfSubstrings(string s) {
        int right = 0 ;
        int left = 0 ;
        vector<int> freq(3,0);
        int total = 0 ;
        while(right < s.length()){
            char currchar = s[right];
            ++freq[currchar - 'a'];
            while ( freq[0] > 0 && freq[1] > 0 && freq[2]>0){
                total += s.size() - right ;
                char leftchar = s[left];
                --freq[leftchar - 'a'];
                left++ ;
            }
            right++;

        }
    return total;   
    }
};