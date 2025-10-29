class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        long long n=0,i=x;
        while(x>0)
        {
            long long a= x%10;
            n = n*10 + a;
            x= x/10;
        }
         
        if(i==n)
            return true;
        else
            return false;
    }
};