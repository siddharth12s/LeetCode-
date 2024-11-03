class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp = s+s;
        return s.size()==goal.size() and temp.find(goal)!=string::npos;
    }
};