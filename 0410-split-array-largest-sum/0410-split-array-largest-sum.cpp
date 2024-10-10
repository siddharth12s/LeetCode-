class Solution {
public:
    bool possible(vector<int> &v, int k, int check_sum){
        int cnt=1;
        int sum=0;

        for(auto x : v){
            sum += x;
            if(sum>check_sum){
                sum = x;
                cnt++;
                if(cnt>k)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int start =  *max_element(nums.begin(),nums.end());
        int end = 0;
        for(auto x : nums)  end+=x;


        while(start<end){
            int mid = start + (end-start)/2;
            if(possible(nums,k,mid)){
                end=mid;
            }else{
                start=mid+1;
            }
        }

        return start;
    }
};