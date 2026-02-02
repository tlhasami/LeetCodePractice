class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>differentCandies(candyType.begin() , candyType.end());

        int maxTypes = candyType.size()/2;
        if (maxTypes > differentCandies.size())
            return differentCandies.size();

        return maxTypes ;
    }
};