class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = 0, currentEmpty = 0;

        while (numBottles > 0) {
            
            count += numBottles;
            currentEmpty += numBottles;
            numBottles = 0;

            
            while (currentEmpty >= numExchange) {
                currentEmpty -= numExchange;
                numBottles++;
                numExchange++;
            }
        }

        return count;
    }
};