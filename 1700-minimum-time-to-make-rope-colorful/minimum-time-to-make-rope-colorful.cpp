class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0 , j = 1 , timeCost = 0 , n = colors.length(); 

        while (i < n && j< n){
            if (colors[i]==colors[j]){
                if (neededTime[i] < neededTime[j]){
                    timeCost += neededTime[i];
                    i=j;
                    j++;
                } else {
                    timeCost += neededTime[j];
                    j++;
                }
            } else {
                i=j;
                j++;
            }
        }

        return timeCost;
        
    }
};

/*
int timeCost = 0 , n = colors.length();
        stack<pair<char,int>>st;
        for (int i = 0 ; i < n ; i++){
            if (!st.empty() && st.top().first==colors[i]){
                //cout << "same " << st.top().first <<st.top().second << " - " << colors[i]<<neededTime[i] << " ";
                if (st.top().second > neededTime[i] ){
                    timeCost += neededTime[i] ;
                    continue;
                } else {
                    timeCost += st.top().second;
                    st.pop();
                    st.push({colors[i],neededTime[i]});
                }

                //cout << timeCost << " " << endl;
            } 
            
            st.push({colors[i],neededTime[i]});
            

        }
        
        return timeCost;
*/