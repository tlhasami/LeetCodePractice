class Solution {
public:
    int minPartitions(string n) {
        
        int maximum = INT_MIN;

        for (auto ch : n){
            if (ch == '9')
                return 9;
            
            maximum = max(ch - '0' , maximum);
        }

        return maximum;
    }
};