class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        
        int max = 0 ;
        for(int i = 0 ; i < n ; i++){
            int total = 0 ;
            int x = accounts[i].size();
            
            for(int j = 0 ; j < x ; j++){
                total = total + accounts[i][j];
                if(total > max){
                    max = total;
                } 
            }
        }
        return max ;
    }
};