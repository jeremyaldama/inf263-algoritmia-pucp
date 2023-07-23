//https://leetcode.com/problems/fibonacci-number
class Solution {
public:
    int fib(int n) {
        if (n<=1) return n;
        int prev1 = 1, prev2 = 0, actual;
        for (int i=2; i<n+1; i++){
            actual = prev1 + prev2;
            prev2 = prev1;
            prev1 = actual;
        }

        return actual;
    }
};