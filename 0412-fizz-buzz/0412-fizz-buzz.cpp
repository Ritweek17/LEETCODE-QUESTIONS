class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        int x = 1;
        vector<string> answer(n);

        for(int i = 0; i < n; i++) {
            
            if((x % 3 == 0) && (x % 5 == 0)) {
                answer[i] = "FizzBuzz";
            }
            else if(x % 3 == 0) {
                answer[i] = "Fizz";
            }
            else if(x % 5 == 0) {
                answer[i] = "Buzz";
            }
            else {
                answer[i] = to_string(x);
            }

            x++;
        }

        return answer;
    }
};