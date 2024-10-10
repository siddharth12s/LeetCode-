class Solution {
public:
    int possible(vector<int> &v, int t, int divisor){
        int sum = 0;
        for(auto x : v){
            if(x%divisor){
                sum += (x/divisor) + 1;
            }else{
                sum += x/divisor;
            }
        }

        return sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(),nums.end());
        int start = 1, end = maxi+1;

        while(start<end){
            int mid = start + (end-start)/2;
            if(possible(nums,threshold,mid)){
                end=mid;
            }else{
                start=mid+1;
            }
        }
        return start;
    }
};