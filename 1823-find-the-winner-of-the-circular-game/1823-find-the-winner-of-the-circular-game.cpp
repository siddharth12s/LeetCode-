class Solution {
public:
int findTheWinner(int n, int k, int res = 0) {
        return n == 1 ? 1 : (k + findTheWinner(n - 1, k) -1) % n + 1;
    }
};