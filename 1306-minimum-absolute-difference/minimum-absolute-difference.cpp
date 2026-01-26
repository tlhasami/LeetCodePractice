class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin() , arr.end());

        int n = arr.size();
        int minDifference = INT_MAX;

        for (int i = 0 ; i < n-1 ; i++){
            minDifference = min( minDifference , arr[i+1] - arr[i]  );
        }

        vector<vector<int>> result;
        for (int i = 0 ; i < n-1 ; i++){
            if ( arr[i+1] - arr[i]  == minDifference)
                result.push_back({arr[i] , arr[i+1]});
        }

        return result;
    }
};