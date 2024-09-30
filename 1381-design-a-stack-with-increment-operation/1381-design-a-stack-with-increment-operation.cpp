class CustomStack {
private:
    vector<int> v;
    int maxsize;
public:
    CustomStack(int maxSize) {
        // v.resize(maxSize);
        maxsize=maxSize;
    }
    
    void push(int x) {
        if(v.size()==maxsize)
            return;
        v.push_back(x);
    }
    
    int pop() {
        if(v.size()==0)
            return -1;
        int elem =v.back();
        v.pop_back();

        return elem;
    }
    
    void increment(int k, int val) {
        cout<<v.size();
        if(v.size()<=k){
            for(auto i=0;i<v.size();i++){
                v[i]+=val;
            }
        }else{
            for(auto i=0;i<k;i++){
                v[i]+=val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */