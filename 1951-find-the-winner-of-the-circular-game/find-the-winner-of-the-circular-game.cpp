class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>people( n , 1);
        int val =1 ;
        for (int& v :people )
            v = val++;
        int i = 0 , count = 1 ;

        while (n != 1){
            if (count == k){
                count = 1;
                //cout << people[i] << " ";
                people.erase(people.begin() + i);
                n --;
            } else {
                 i = (i+1)%n ; 
                 count++;
            }
            
        }

        return people[0];


    }
};