class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n = s.size() , m = g.size() , count = 0;

        int greed = 0 , size = 0; 

        while (greed < m && size < n){
            if (g[greed] <= s[size]){
                greed++ , size++;
                count++;
            }
            else
                size++;
        }

        return count;
    }
};