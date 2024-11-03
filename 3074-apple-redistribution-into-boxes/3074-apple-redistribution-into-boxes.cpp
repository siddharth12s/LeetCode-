class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totapp = 0;
        for(auto x : apple){
            totapp+=x;
        }

        int cnt = 0;
        sort(capacity.begin(),capacity.end(),greater<int>());

        for(auto i=1;i<capacity.size();i++){
            capacity[i] += capacity[i-1];
        }

        for(auto x : capacity){
            if(x>=totapp){
                cnt++;
                break;
            }else{
                cnt++;
            }
        }
        return cnt;
    }
};