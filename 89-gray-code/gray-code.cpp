class Solution {
public:
    string numberToBinary(int n){
        string binary = "";
        while (n > 0){
            binary.append( n&1 ? "1": "0");
            n >>= 1;
        }

        reverse(binary.begin(), binary.end());

        return binary;
    }

    int binaryToNumber(string bin){
        int val = 0 , n = bin.length() , idx = 0;
        for (int i = n-1; i >=0 ; i--){
            if (bin[i] == '1')
                val += 1<<idx;

            ++idx;
        }

        return val;
    }

    int getGreyCode(int n){
        string bin = numberToBinary(n);

        if (bin.length() < 1) return bin.length();
        int size = bin.length() ;
        string grey(size , '0');

        grey[0] = bin[0];

        for (int i = 1 ; i < size ; i++){
            if ((bin[i]-'0')^(bin[i-1]-'0'))
                grey[i] = '1';
            else
                grey[i] = '0';
        }
        
        return binaryToNumber(grey);
    }

    // vector<int> grayCode(int n) {
    //     vector<int>result;
    //     int maxRange = 1<<(n) ;
    //     --maxRange;
    //     //cout << "GAME : " << maxRange << endl;

    //     for (int i = 0 ; i <= maxRange ; i++){
    //         //cout << i << " " << getGreyCode(i) << endl;
    //         result.push_back(getGreyCode(i));
    //     }

    //     return result;
    // }

    vector<int> grayCode(int n) {
        int total = 1 << n;
        vector<int> res(total);
        for (int i = 0; i < total; i++) 
            res[i] = (i ^ (i >> 1));
        return res;
    }
};