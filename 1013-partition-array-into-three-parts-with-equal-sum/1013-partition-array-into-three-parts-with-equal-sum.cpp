class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int k = 0;
        int sum = 0;
        for(auto x : arr){
            sum += x;
        }

        if(sum%3)
            return false;
        
        k = sum/3;
        int cnt=0;

        int sum2 = 0;
        for(auto x:arr){
            sum2 += x;
            if(sum2==k){
                cnt++;
                sum2=0;
            }
        }

        return cnt>=3 and sum%3==0;
    }
};