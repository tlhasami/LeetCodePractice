class Solution {
public:
    vector<int> sortByBits(vector<int>& nums) {
        vector<pair<int,int>>values;

        for (int& num : nums){
            
            int first = 0 , second = num;
            while (num > 0){

                if (num%2 == 1)
                    first++;
                
                num>>=1;
            }

            values.push_back({first,second});
        }

        sort(values.begin() , values.end());

        int n = nums.size();
        for (int i = 0 ; i < n ; i++){
            nums[i] = values[i].second;
        }

        return nums;
    }
};