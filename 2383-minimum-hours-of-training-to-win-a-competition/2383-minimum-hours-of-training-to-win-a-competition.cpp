class Solution {
public:
    int minNumberOfHours(int iniEn, int iniEx, vector<int>& energy, vector<int>& exp) {
           int ans = 0;
           for(auto i=0;i<energy.size();i++){
                    if(iniEn<=energy[i]){
                        int diff = energy[i] - iniEn;
                        ans += diff + 1;
                        iniEn += diff + 1;
                    }
                    if(iniEx<=exp[i]){
                        int diff = exp[i] - iniEx;
                        ans += diff+1;
                        iniEx += diff+1;
                    }
                    iniEn-=energy[i];
                    iniEx += exp[i];
           }

           return ans;
    }
};