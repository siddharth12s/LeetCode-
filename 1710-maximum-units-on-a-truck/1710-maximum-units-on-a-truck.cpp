class Solution {
public:
    static bool compare(vector<int> & a,vector<int> &b){
        return a[1]<b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int ans=0;
        int n=boxTypes.size();
        int i = n-1;
         while(truckSize>0 and i>-1){
                 ans += min(boxTypes[i][0],truckSize)*boxTypes[i][1];
                 truckSize -= boxTypes[i][0];
                 i--;
         }
        return ans;
    }
};