class Solution {
public:
    int firstDigit(int n) {
        while (n >= 10) {
            n /= 10;
        }
        return n;
    }

    long long countBeautifulPairs(vector<int>& nums) {
        long long ans = 0;
        int freq[10] = {};

        for (int x : nums) {
            int last = x % 10;

            for (int first = 1; first <= 9; first++) {
                if (freq[first] > 0 && gcd(first, last) == 1) {
                    ans += freq[first];
                }
            }

            int first = firstDigit(x);
            freq[first]++;
        }

        return ans;
    }
};