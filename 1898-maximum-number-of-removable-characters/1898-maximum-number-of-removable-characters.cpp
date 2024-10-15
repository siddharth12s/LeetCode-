class Solution {
public:
    bool feasible(string text, string pattern, int idx,vector<int> &rem){
        vector<int> v(text.size(),0);

        for(auto i=0;i<idx;i++){
            v[rem[i]]=1;
        }

        int i=0,j=0;
        while(i<text.size() and j<pattern.size()){
            if(text[i]==pattern[j] and !v[i]){
                i++;
                j++;
            }else{
                i++;
            }
        }

        return j==pattern.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        // sort(removable.begin(),removable.end());
        int start=0,end=removable.size();
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(feasible(s,p,mid,removable)){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};