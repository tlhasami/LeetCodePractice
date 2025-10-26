class Bank {
public:
    vector<long long> bank;
    Bank(vector<long long>& balance) {
        bank = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 <= bank.size() && account2 <= bank.size() && money >= 0 && bank[account1-1] >= money){
            deposit(account2,money);
            withdraw(account1,money);
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (account <= bank.size() && money >= 0){
             bank[account-1] += money;
            return true;
        }

        return false;
    }
    
    bool withdraw(int account, long long money) {
        if (account <= bank.size() && bank[account-1] >= money){
            bank[account-1] -= money;
            return true;
        }

        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */