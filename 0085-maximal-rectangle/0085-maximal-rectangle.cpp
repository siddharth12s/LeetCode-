class Solution {
public:
    int mah(vector<int> v1){
        
        v1.push_back(0);
        stack<int> index;
        // index.push(0);
        int ans = 0;

        for(auto i=0;i<v1.size();i++){
            while(!index.empty() and v1[index.top()]>v1[i]){
                int height = v1[index.top()];
                index.pop();

                int l = index.empty()?-1:index.top();
                ans = max(ans,(i-l-1)*height);
            }
            index.push(i);
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int ans = 0;
        vector<vector<int>> temp(matrix.size(),vector<int> (matrix[0].size()));

        for(auto i = 0;i<matrix.size();i++){
            if(i!=0){
                for(auto j=0;j<matrix[0].size();j++){
                    if(matrix[i][j]-'0'!=0)
                        temp[i][j] = temp[i-1][j]  + (matrix[i][j]-'0');
                    else
                        temp[i][j] = 0;
                }

            }else{
                for(auto j=0;j<matrix[0].size();j++){
                    temp[i][j] =  matrix[i][j]-'0';
                }
            }
        }

        // for(auto x: temp){
        //     for(auto y : x){
        //         cout<<y<<",";
        //     }
        //     cout<<endl;
        // }
        for(auto i=0;i<temp.size();i++){
            ans= max(ans,mah(temp[i]));
        }

        return ans;
    }
};