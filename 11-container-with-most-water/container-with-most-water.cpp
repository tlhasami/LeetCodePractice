class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0 , right = height.size()-1 , maxWater = 0;

        while (left < right){
            int length = right - left ;
            int width = min (height[right], height[left]);

            maxWater = max(maxWater , length*width);

            if (height[left] < height[right]) left++;
            else right--;
        }

        return maxWater;
    }
};