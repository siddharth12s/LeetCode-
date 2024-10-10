class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0, end = arr.size();
        int missing_nos;
        while(start<end){
            int mid = start + (end-start)/2;
            missing_nos = arr[mid]-(mid+1);

            if(missing_nos>=k){
                end=mid;
            }else{
                start=mid+1;
            }
        }

        return start+k;
    }
};