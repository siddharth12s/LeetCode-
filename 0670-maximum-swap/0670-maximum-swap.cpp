class Solution {
public:
    int maximumSwap(int num) {
        int ans = 0;
        int pos = 0;
        string temp = to_string(num);
        int mini_pos=-1,mini_num=9;
        int maxi_pos=0,maxi_num=0;

        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i]-'0'>maxi_num){
                maxi_num = temp[i]-'0';
                maxi_pos=i;
            }
        }

        mini_num=maxi_num;

        for(auto i=0;i<maxi_pos;i++){
            if(temp[i]-'0'<maxi_num){
                mini_pos=i;
                break;
            }
        }
        if (mini_pos == -1) return num;
        swap(temp[mini_pos],temp[maxi_pos]);
        return stoi(temp);
    }
};