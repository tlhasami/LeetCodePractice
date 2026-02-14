class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        stack<int>st1;
        stack<int>st2;

        for (int num : nums){
            if (num < 0)
                st1.push(num);
            else 
                st2.push(num);
        }

        int index = nums.size()-1;
        while (!st1.empty() && !st2.empty()){
            int neg = st1.top();  st1.pop();
            int pos = st2.top();  st2.pop();

            nums[index] = neg;
            nums[index-1] = pos;

            index-=2;
        }

        return nums;
    }
};