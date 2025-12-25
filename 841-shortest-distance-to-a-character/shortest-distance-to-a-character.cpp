class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>places;
        vector<int>result;

        int n = s.length();
        result.reserve(n);

        for (int i = 0 ; i < n ; i++){
            if (s[i] == c)
                places.push_back(i);
        }

        int index = 0 , noOfPlaces = places.size();
        for (int i = 0; i < n ; i++){
            if (index+1 < noOfPlaces && abs(places[index] - i) < abs(places[index+1] - i)){
                result.push_back(abs(places[index] - i));
            } else if (index+1 < noOfPlaces) {
                result.push_back(abs(places[index+1] - i));
                index++;
            } else {
                result.push_back(abs(places[index] - i));
            }
        }

        return result;

    }
};