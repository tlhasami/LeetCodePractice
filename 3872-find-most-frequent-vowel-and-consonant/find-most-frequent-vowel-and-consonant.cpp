class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<int,int> freq1;
        unordered_map<int,int> freq2;
        for (auto & a: s){
            if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
                freq1[a]++;
            } else {
                freq2[a]++;
            }
        }

        int max1 = 0 , max2 = 0;
        for(auto& [key,value] : freq1) max1 = max(max1 , value);
        for(auto& [key,value] : freq2) max2 = max(max2 , value);

        return max1+max2;
    }
};