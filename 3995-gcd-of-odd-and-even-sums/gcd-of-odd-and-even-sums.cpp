class Solution {
public:

    int gcd(int a,int b){
        if (b==0) return a;
        return gcd(b , a%b);
    }

    int gcdOfOddEvenSums(int n) {
        //3ms
        // int e  = 0, o = 0;

        // for (int i = 1 ; i <= n*2 ; i++){
        //     if ( i & 1 ) o += i;
        //     else e += i;
        // }

        // return gcd(e,o);

        return n;
    }
};
