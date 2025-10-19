class Solution {
public:
    int numberOfBeams(vector<string>& banks) {
        int result = 0 ;
        int prev = 0 ;
        for (string& bank : banks){
            int curr = 0;
            for (char laser : bank){
                if (laser == '1') curr++;
            }

            result += prev*curr;
            prev = curr > 0 ? curr : prev ;
        }

        return result;
    }
};