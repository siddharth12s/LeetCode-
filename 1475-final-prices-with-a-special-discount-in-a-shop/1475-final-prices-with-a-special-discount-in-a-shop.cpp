class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        
        vector<int> ans;
        int n= prices.size()-1;
        s.push(-1);
        
        
        for(auto i=n;i>=0;i--){
            int curr=prices[i];
            while(s.top()>curr){
                s.pop();
            }
            if(s.top()==-1)
                ans.push_back(curr);
            else
                ans.push_back(curr-s.top());
            s.push(curr);
        }
        
        for(auto i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
         reverse(ans.begin(),ans.end());
        return ans;
    }
};