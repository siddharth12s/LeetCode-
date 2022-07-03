class Solution {
public:
    int wiggleMaxLength(vector<int>& num) {
        int n = num.size();
        if(n==1 or n==0)
            return n;
        vector<int> up(n,0),down(n,0);
        up[0]=down[0]=1;
        for(auto i=1;i<n;i++){
            if(num[i]>num[i-1]){
                up[i]=down[i-1]+1;
                down[i]=down[i-1];
            }
            else if(num[i]<num[i-1]){
                down[i]=up[i-1]+1;
                up[i]=up[i-1];
            }
            else{
                down[i]=down[i-1];
                up[i]=up[i-1];
            }
        }
        return max(down[n-1],up[n-1]);
    }
};