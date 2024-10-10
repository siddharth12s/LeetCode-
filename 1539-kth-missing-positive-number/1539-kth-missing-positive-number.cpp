class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int maxi = *max_element(arr.begin(),arr.end());

        for(auto x : arr){
            if(x<=k)
                k++;
            else
                break;
        }

        return k;
    }
};