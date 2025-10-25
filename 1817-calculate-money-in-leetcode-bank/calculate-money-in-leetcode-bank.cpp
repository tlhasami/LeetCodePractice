class Solution {
public:
    int totalMoney(int n) {
        int result = 0 , adder = 1, step = 1;

        for (int i = 1 ; i <= n ; i++){
            result += adder++;

            if (i%7==0){
                adder = ++step;
            }
        }
        

        return result;
        
    }
};