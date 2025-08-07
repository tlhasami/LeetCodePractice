class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        queue<int> tickets(t.begin(),t.end());

        int min = 0;

        while(!tickets.empty()){
            cout << tickets.front() << " ";
            if (k == 0 && tickets.front() == 1)
                return min + 1;
            else if (tickets.front() == 1 ){
                tickets.pop();
            }
            else if (tickets.front() > 1){
                int add = tickets.front() - 1;
                tickets.pop();
                tickets.push(add);

            }

            min ++;
            
            k --;
            if (k == -1){
                k = tickets.size() - 1;
            }

        }

        return min ;
    }
};