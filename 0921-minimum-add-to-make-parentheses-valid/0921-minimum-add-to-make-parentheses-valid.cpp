class Solution {
public:
    int minAddToMakeValid(string s) {
        int left=0, right=0;

        for(auto &c : s){
            if(c=='('){
                right++;
            }
            else if (right==0){
                left++;
            }else{
                right--;
            }
        }

        return left+right;
    }
};