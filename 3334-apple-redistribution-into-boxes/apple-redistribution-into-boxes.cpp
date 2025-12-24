class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end() , greater<int>());
        int sum = accumulate(apple.begin(), apple.end(), 0);

        int carts = 0;

        for (auto& cap : capacity){
            sum-=cap;
            carts++;
            if (sum<=0) return carts;
        }

        return carts;

    }
};