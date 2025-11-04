class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;


        for (int i = 0 ; i < n-k+1 ; i++){
            vector<pair<int,int>>val(51, {0,0});
            for (int j = i ; j < k+i ; j++){
                val[nums[j]].first = nums[j];
                val[nums[j]].second += 1 ;
            }

            sort(val.begin(), val.end() , [](pair<int,int>& a , pair<int,int>&b){
                if (a.second > b.second){
                    return true;
                }else if (a.second == b.second && a.first > b.first){
                    return true;
                }

                return false;
            });
            int idx = 0 ;
            int sum = 0 ;
            for (auto& v : val){
                if (idx < x ){
                    sum += v.first*v.second;
                    idx++;
                } else {
                    break;
                }
                    
                
                //cout <<v.first << "*" <<v.second <<"=" <<sum<< " - ";
                
            } cout <<endl;

            result.push_back(sum);

        }
        

        return result;
    }
};