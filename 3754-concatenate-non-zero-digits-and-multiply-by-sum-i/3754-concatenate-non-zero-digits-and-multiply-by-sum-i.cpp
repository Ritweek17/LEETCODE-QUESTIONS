class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);

        string x = "";
        long long sum = 0;

        for(char ch : s) {
            if(ch != '0') {
                x += ch;
                sum += ch - '0';
            }
        }

        if(x.empty()) return 0;

        long long num = stoll(x);

        return num * sum;
    }
};