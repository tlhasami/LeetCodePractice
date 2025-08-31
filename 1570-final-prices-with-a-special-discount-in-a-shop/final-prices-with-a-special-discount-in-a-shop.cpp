class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>discounted_price;
        int n = prices.size();
        discounted_price.reserve(n);

        for (int i = 0 ; i < n - 1 ;i++){
            bool found = false;
            for (int j = i+1 ; j < n ; j++){
                if (prices[j] <= prices[i]){
                    discounted_price.push_back(prices[i]-prices[j]);
                    found = true;
                    break;
                }
            }

            if (!found)
                discounted_price.push_back(prices[i]);
        }

        discounted_price.push_back(prices[n-1]);

        return discounted_price;

    }
};