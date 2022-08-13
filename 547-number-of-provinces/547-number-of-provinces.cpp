class Solution {
public:
    int find(int v, int parent[]){
        if(parent[v]==v)    return v;
        
        return parent[v]=find(parent[v],parent);
    }
    
    void Union(int a ,int b, int parent[]){
        a = find(a,parent);
        b = find(b,parent);
        
        if(a!=b)
            parent[b]=a;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       
        int n = isConnected.size();
        
        int parent[n];
        for(auto i=0;i<n;i++)   parent[i]=i;
        
        
        int ans=0;
        for(auto i=0;i<n;i++){
            for(auto j=i+1;j<n;j++){
                if(isConnected[i][j])   Union(i,j,parent);
            }
        }
        
        for(auto i=0;i<n;i++){
            if(parent[i]==i)    ans++;
        }
        
        return ans;
    }
};