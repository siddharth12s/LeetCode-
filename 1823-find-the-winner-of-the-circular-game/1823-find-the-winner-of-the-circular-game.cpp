class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> q;
        for(auto i=1;i<=n;i++){
            q.push_back(i);
        }
        int f =0;
        while(q.size()>1){
            if(f>=q.size()-1 or (f+k-1)>q.size()-1){
                f=(f+k-1)%q.size();
            }
            else{
                f+=k-1;
            }
            q.erase(q.begin()+f);
        }
        return q[0];
    }
};