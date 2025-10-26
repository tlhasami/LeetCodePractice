class ATM {
public:
    vector<long long> notes; 
    vector<int> values = {20, 50, 100, 200, 500};

    ATM() {
        notes = vector<long long>(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            notes[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> toSend(5, 0);
        int remaining = amount;

        for (int i = 4; i >= 0; i--) {
            long long take = min((long long)(remaining / values[i]), notes[i]);
            toSend[i] = take;
            remaining -= take * values[i];
        }

        
        if (remaining != 0) return {-1};

        
        for (int i = 0; i < 5; i++) {
            notes[i] -= toSend[i];
        }

        return toSend;
    }
};
/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */