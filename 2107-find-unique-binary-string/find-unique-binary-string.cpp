#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    string nextWord(unordered_set<string>& s, int n, string current){

        if(current.size() == n){
            if(s.find(current) == s.end())
                return current;
            return "";
        }

        string zero = nextWord(s, n, current + "0");
        if(zero != "") return zero;

        string one = nextWord(s, n, current + "1");
        return one;
    }

    string findDifferentBinaryString(vector<string>& nums) {

        unordered_set<string> s(nums.begin(), nums.end());
        int n = nums.size();

        return nextWord(s, n, "");
    }
};