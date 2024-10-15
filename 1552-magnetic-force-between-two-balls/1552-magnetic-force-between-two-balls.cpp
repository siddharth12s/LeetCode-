class Solution {
public:
    bool feasible(vector<int> &v,int m,int mid){
        int cnt = 1,last = v[0];
        for(auto i=1;i<v.size();i++){
                if(v[i]-last>=mid){
                    last=v[i];
                    cnt++;
                }

                if(cnt>=m){
                    return true;
                }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        
        int max_elem = *max_element(position.begin(),position.end());
        int min_elem = *min_element(position.begin(),position.end());

        int start = 1,end=max_elem-min_elem;
        int ans = end;
        while(start<=end){
            int mid = start + (end-start)/2;
            if (!feasible(position,m,mid)){
                end=mid-1;
            }else{
                // ans = mid;
                start=mid+1;
            }
        }
        return end;
    }
};