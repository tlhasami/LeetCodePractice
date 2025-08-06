class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
        unordered_map<int ,int> freq;    
        for (int n : nums)
            freq[n]++;
        
        int result = -1 , f = 0;
        for (auto [value, count] : freq){
           // cout << value << " " << count << endl ;
            if (value % 2 == 0 && count >= f){
                if (count == f)
                    result = result < value ? result : value;
                else 
                    result = value;
                f = count;
            }
        }

        return result;


        
    }
};