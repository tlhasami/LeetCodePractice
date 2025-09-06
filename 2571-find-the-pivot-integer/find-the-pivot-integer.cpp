class Solution {
public:
    int pivotInteger(int n) {
        long long total = (n * (n+1))/2;
        for (int i = 1 ; i <= n ; i++){
            long long right =  total - ((i-1) * (i))/2;
            long long left = ((i) * (i+1))/2;
            if (right == left) return i;
        }

        return -1;

    }
};