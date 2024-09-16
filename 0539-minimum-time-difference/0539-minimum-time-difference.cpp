class Solution {
public:

    int time_diff(string &s1){
        int hour = stoi(s1.substr(0,2));
        int minute = stoi(s1.substr(3));
        
        return hour*60 + minute;
    }
    int findMinDifference(vector<string>& timePoints) {
        
        int ans = INT_MAX;
        int n = timePoints.size();

        vector<int> diff;
        for(auto i=0;i<n;i++){
            int val = time_diff(timePoints[i]);

            diff.push_back(val);
        }

        sort(diff.begin(),diff.end());

        for(auto i=1;i<n;i++){
            ans =  min(abs(diff[i]-diff[i-1]),ans);
        }

        return min(ans, 24*60-diff[diff.size()-1]+diff[0]);
        
    }
};