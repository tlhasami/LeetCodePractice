class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // return true;

        sort(piles.begin() , piles.end() , greater<int>());
        
        int alice = 0 , bob = 0 , i = 0 , end = piles.size();
        
        while (i < end){
            alice += piles[i++];
            bob += piles[i++];
        } 

        return (alice > bob) ? true: false;

        
    }
};