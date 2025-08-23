class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.size() > 0 && bills[0] == 10 || bills[0] == 20 )
            return false;

        vector<int> change({0,0,0});

        for (auto& bill : bills){
            if (bill == 5)
                change[0] ++;
            else if (bill == 10 && change[0])
                change[0]--,change[1]++;
            else if (bill == 20 ){
                if (change[0] && change[1]){
                    change[0]--, change[1]--;
                } else if (change[0] >= 3)
                    change[0]-=3;
                else 
                    return false;
            } else
                return false;
        }

        return true;
    }
};