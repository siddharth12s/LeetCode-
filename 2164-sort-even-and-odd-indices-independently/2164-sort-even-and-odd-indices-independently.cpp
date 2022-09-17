class Solution {
public:

    vector<int> sortEvenOdd(vector<int>& nums) {
       vector<int> even,odd;
        int n = nums.size();
        for(auto i=0;i<n;i++){
            if(i%2)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end());
        
        int j=0,k=0;
        for(auto i=0;i<n;i++){
            if(i%2){
                nums[i]=odd[j];
                j++;
            }
            else{
                nums[i]=even[k];
                k++;
            }
        }
        return nums;
    }
};