class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> key_index;
        int n = nums1.size() , m = nums2.size() ;

        for (int i = 0 ; i < m ; i++){
            key_index[nums2[i]] = i;
        }

        vector<int> result (n , -1);
        for (int i = 0 ; i < n ; i++){
            for (int j = key_index[nums1[i]] + 1 ; j < m ; j++){
                if (nums2[j] >= nums1[i]){
                    result[i] = nums2[j];
                    break;
                }
            }
        }

        return result;
    }
};