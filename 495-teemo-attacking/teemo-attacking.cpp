class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int count = 0 , n = timeSeries.size();
        for (int i = 0 ; i < n - 1 ;i++){
            if (timeSeries[i+1] - timeSeries[i] >= duration){
                count += duration;
            } else {
                count += timeSeries[i+1] - timeSeries[i] ;
            }
        }

        return count+duration;
    }
};