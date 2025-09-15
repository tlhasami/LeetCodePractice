class BrowserHistory {
public:
    list<string> status;
    list<string>::iterator curr ;
    BrowserHistory(string homepage) {
        status.push_back(homepage);
        curr = status.begin();
    }
    
     void visit(string url) {
        auto it = curr;
        ++it;
        status.erase(it, status.end());  
        status.push_back(url);
        curr = prev(status.end());       
    }
    
    string back(int steps) {
        while (steps > 0 && curr != status.begin()) {
            --curr;
            --steps;
        }
        return *curr;
    }
    
    string forward(int steps) {
        while (steps > 0 && next(curr) != status.end()) {
            ++curr;
            --steps;
        }
        return *curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */