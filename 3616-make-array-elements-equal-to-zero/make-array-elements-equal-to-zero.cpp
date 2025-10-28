class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size() , count = 0;

        vector<int>left(n , 1);
        vector<int>right(n , 1);

        left[0] = nums[0];
        for (int i = 1 ; i < n ; i++)
            left[i] = left[i-1] + nums[i];

        right[n-1] = nums[n-1];
        for (int i = n-2 ; i >= 0 ; i--)
            right[i] = right[i+1] + nums[i];

        // for (int& a : left )    cout << a << " "; 
        // cout << endl;

        // for (int& a : right )    cout << a << " "; 
        // cout << endl;


        for (int i = 0 ; i < n ; i++){
            if (nums[i] == 0){
                if (left[i] == right[i]){
                    count += 2;
                } else if (left[i]-1 == right[i] || left[i] == right[i] -1) {
                    count ++;
                }
            }
        }
        
        return count;
    }
};