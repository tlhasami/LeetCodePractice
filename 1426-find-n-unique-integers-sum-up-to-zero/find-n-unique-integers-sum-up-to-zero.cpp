class Solution {
public:
    vector<int> sumZero(int n) {
        deque<int> values;

        bool toAdd = (n%2)? true:false;

        if (toAdd) n--;

        while(n > 0){
            values.push_front(-n);
            values.push_back(n);

            n-=2;
        }

        if (toAdd){
            values.push_back(0);
        }

        vector<int>val(values.begin(),values.end());
        return val;

    }
};