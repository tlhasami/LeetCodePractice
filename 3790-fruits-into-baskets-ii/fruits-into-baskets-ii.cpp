class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int n = baskets.size();

        int count = 0;

        for(int i = 0 ; i < n ; i++){
            bool occupied = false;
            for (int j = 0 ; j < n ; j++){
                if (fruits[i] <= baskets[j]){
                    baskets[j] = 0;
                    occupied = true;
                    break;
                }
            }
            if (!occupied)
                count++;
        }

        return count;

    }
};