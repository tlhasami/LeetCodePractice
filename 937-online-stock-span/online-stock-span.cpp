#include <iostream>
#include <vector>
using namespace std;

class StockSpanner {
public:
    vector<int> val;

    StockSpanner() {}

    int next(int price) {
        val.push_back(price);

        int count = 1;
        int n = val.size();

        // Go backwards to count consecutive smaller or equal prices
        for (int i = n - 2; i >= 0; i--) {
            if (val[i] <= price)
                count++;
            else
                break; // stop when we find a larger price
        }

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
