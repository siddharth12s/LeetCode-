class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<int> vis(nums.size(),0);

        for(auto i=0;i<nums.size();i++){
            vis[i]=0;
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        for(auto i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        long long score = 0;

        int visited =0;

        while(!pq.empty()){
            auto [elem, index] = pq.top();
            if(vis[index]){
                pq.pop();
                continue;
            }else{

                score += elem;

                vis[index] = 1;
                if(index>=1 and index<nums.size()-1){
                    vis[index-1] = vis[index+1] =1;
                }else if(index==0){
                    vis[index+1] = 1;
                }else if(index=nums.size()-1){
                    vis[index-1] = 1;
                }
                pq.pop();
            }

            cout<<elem<<" "<<index<<endl;
        }

        

        return score;
    }
};