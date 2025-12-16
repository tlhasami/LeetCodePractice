class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        bool up = true , found1 = false , found2 = false;
        int n = arr.size();

        if (n < 3) return false;
        
        for (int i = 1 ; i < n ; i++){
            if (up && arr[i-1] < arr[i])
                found1 = true;
            else if (up && arr[i-1] > arr[i]){
                found2 = true;   
                up = false;
            }
            else if (!up && arr[i-1] > arr[i])
                continue;
            else 
                return false;
                
        }

        return found1 && found2 ;
    }
};