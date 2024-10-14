struct Compare{
    bool operator()(const pair<int,int> &p1,const pair<int,int> &p2){
        double a = (double)p1.first/(double)p1.second;
        double b = (double)p2.first/(double)p2.second;

        return a>b;
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>> , Compare> max_frac;

        for(auto i=0;i<arr.size()-1;i++){
            for(auto j=i+1;j<arr.size();j++){
                max_frac.push({arr[i],arr[j]});
            }
        }

        while(!max_frac.empty() and k>1){
            max_frac.pop();
            k--;
        }

        return {max_frac.top().first,max_frac.top().second};
    }
};