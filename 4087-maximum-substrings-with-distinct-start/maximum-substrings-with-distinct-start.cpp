class Solution {
public:
    int maxDistinct(string s) {
        set<char>result(s.begin() , s.end());
        return result.size();
    }
};