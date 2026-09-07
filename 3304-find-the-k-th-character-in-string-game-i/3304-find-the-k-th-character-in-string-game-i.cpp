class Solution {
public:
    char kthCharacter(long long k) {
        k--;

        int count = 0;

        while (k > 0) {
            count += k & 1;
            k >>= 1;
        }

        return 'a' + (count % 26);
    }
};