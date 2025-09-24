class Solution {
public:
    vector<int> recoverOrder(vector<int>& orders, vector<int>& friends) {
        vector<int>finishedOrder;
        finishedOrder.reserve(friends.size());

        unordered_set<int> exist (friends.begin() , friends.end());

        for (int order: orders){
            if (exist.find(order) != exist.end())
                finishedOrder.push_back(order);
        }

        return finishedOrder;
    }
};