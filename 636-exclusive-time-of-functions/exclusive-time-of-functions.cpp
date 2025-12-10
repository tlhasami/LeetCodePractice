class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int,int>>st;

        vector<int>timeStamps(n , 0);


        for (const auto& log : logs){

            string part1, status, part3;

            stringstream ss(log);

            getline(ss, part1, ':');   
            getline(ss, status, ':');   
            getline(ss, part3);        

            int id = stoi(part1);
            int timeStamp = stoi(part3);

            if (status == "start"){
                if (!st.empty()){
                    auto& [i,t] = st.top();
                    timeStamps[i] += timeStamp-t;
                }
                st.push({id,timeStamp});
            } else {
                auto temp = st.top();
                timeStamps[temp.first] += timeStamp - temp.second+1;
                st.pop();

                if (!st.empty()){
                    auto& [i,t] = st.top();
                    t = timeStamp+1;
                }
            }

        }

        return timeStamps;

    }
};