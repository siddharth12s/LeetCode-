class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int maxi = *max_element(arr.begin(),arr.end());

        unordered_set<int> s;
        for(auto x : arr){
            s.insert(x);
        }
        
        int ans=1;
        for(auto i=1;i<=1000000;i++){
            if(s.count(i)==0){
                k--;
            }

            if(k==0){
                ans=i;
                break;
            }
        }

        return ans;
    }
};