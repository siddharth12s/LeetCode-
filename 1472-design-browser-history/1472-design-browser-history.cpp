class BrowserHistory {
public:
    vector<string> v;
    int pos=0;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
    }
    
    void visit(string url) {
        pos++;
        v.resize(pos);
        v.push_back(url);
    }
    
    string back(int steps) {
        pos = max(0,pos-steps);
        return v[pos];
    }
    
    string forward(int steps) {
        pos= min(int(v.size()-1),pos+steps);
        return v[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */