class Solution {
public:
    static bool comp(pair<int,int> p1,pair<int,int> p2){
        if(p1.second==p2.second)
            return p1.first>p2.first;
        
        return p1.second<p2.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> m;
        vector<pair<int,int>> temp;
        
        for(auto x : nums){
            m[x]++;
        }
        
        for(auto x : m){
            temp.push_back({x.first,x.second});
        }
        
        sort(temp.begin(),temp.end(),comp);
        // nums.clear();
        int k=0;
        for(auto x : temp){
            for(auto j=0;j<x.second;j++){
                nums[k]=x.first;
                k++;
            }
        }
        return nums;
    }
};