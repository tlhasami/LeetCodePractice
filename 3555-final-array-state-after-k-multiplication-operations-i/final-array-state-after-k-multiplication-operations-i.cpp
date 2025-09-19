class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        int idx = 0 ;
        for (int num : nums)
            minHeap.push({num,idx++});
        
        while ( k > 0 ){
            auto [val,idx] = minHeap.top() ;
            minHeap.pop(); 
            minHeap.push({val * multiplier ,idx });
            k--;
        }

        while (!minHeap.empty()){
            auto [val,idx] = minHeap.top() ;minHeap.pop();
            nums[idx] = val ;

        }

        return nums;

    }
};
