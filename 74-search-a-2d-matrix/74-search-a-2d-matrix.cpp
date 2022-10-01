class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        vector<int> a;
        for(auto x :matrix){
            a.insert(a.end(),x.begin(),x.end());
        }
        
        int start=0;
        int end = a.size()-1;
        bool flag=false;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(target<a[mid]){
                end = mid-1;
            }
            else if(target==a[mid]){
                flag=true;
                break;
            }
            else{
                start=mid+1;
            }
        }
        for(auto x : a){
            cout<<x<<" ";
        }
        
        return flag;
    }
};