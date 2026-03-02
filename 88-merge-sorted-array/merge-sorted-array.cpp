class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x = 0 , y = 0;

        vector<int>result;
        while (x < m && y < n){
            if (nums1[x] < nums2[y]){
                result.push_back(nums1[x]);
                x++;
            } else {
                result.push_back(nums2[y]);
                y++;
            }
            
        }

        while (x < m){
            result.push_back(nums1[x]);
            x++;
        }

        while (y < n){
            result.push_back(nums2[y]);
            y++;
        }

        nums1 = result;
       
    }
};