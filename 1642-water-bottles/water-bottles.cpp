class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = 0 , currentEmpty = 0;

        while (numBottles > 0){
            int bottle = numBottles;
            count += numBottles;
            numBottles = (bottle + currentEmpty) / numExchange;
            currentEmpty = (bottle + currentEmpty) % numExchange;
        }

        return count;
    }
};