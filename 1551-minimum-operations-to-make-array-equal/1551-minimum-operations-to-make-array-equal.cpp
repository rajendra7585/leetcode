class Solution {
public:
    int minOperations(int n) {
        int k = 0;
        for (int i = 0; i < n / 2; i++) {
            k += n - (2 * i + 1);
        }
        return k;
    }
};