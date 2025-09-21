class Solution {
public:
    void bfs(vector<string>& result , string curr , int n){
        int size = curr.length();
        if (size == n){
            result.push_back(curr);
            return;
        }
        if (curr[size-1] == '0'){
            bfs(result, curr + "1" , n);
        }
        else {
            bfs(result, curr + "0" , n);
            bfs(result, curr + "1" , n);
        } 
    }
    vector<string> validStrings(int n) {
        vector<string>result;
        bfs(result, "0" , n);
        bfs(result, "1" , n);
        return result;
    }
};