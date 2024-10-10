class Solution {
public:
    int possible(vector<int> &w, int capacity, int D){
        int days = 1;
        int sum = 0;
        for(auto weight : w){
            sum += weight;
            if(sum > capacity){
                sum=weight;
                days+=1;
                if(days>D)
                    return 0;
            }
        }
        return 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int least_capacity = INT_MIN;
        for(auto x : weights){
            sum += x;
            least_capacity=max(least_capacity,x);
        }
        int end = sum+1;
        int start = least_capacity;

        while(start<end){
            int mid = start + (end-start)/2;
            if(possible(weights,mid,days)){
                end = mid;
            }else{
                start=mid+1;
            }
        }
        
        return start;
    }
};