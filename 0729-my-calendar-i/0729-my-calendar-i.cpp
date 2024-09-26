class MyCalendar {
private:
    vector<pair<int,int>> booking;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool flag = 1;
        for(auto [s,e] : booking){
            if(start<e and s<end)
                return false;
        }

        // if(flag){
            booking.push_back({start,end});
            return true;
        // }

        // return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */