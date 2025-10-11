class Solution {
public:
    int minimumChairs(string s) {
        int result = 0 , count = 0;
        for (char status : s){
            if (status == 'E'){
                count++;
                result = max(result,count);
            } else {
                count--;
            }
        }

        return result;
    }
};