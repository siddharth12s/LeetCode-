// class Solution {
// public:
//     bool isFeasible(vector<int> &c, vector<int> &r, int k, long long mid){
//         long long sum = 0;
//         long long start=0,end=0;
//         long long maxi = (long long)c[0];
//         deque<long long> dq;
//         while(end<c.size()){
//             sum += r[end];
//             // if dq.size() is equal to mid(window which we are trying to find out)
//             // if(!dq.empty() and dq.front()==end-mid) dq.pop_front();
//             while(!dq.empty() and c[dq.back()] < c[end]){
//                 dq.pop_back();
//             }
//             dq.push_back(end);

//             if(end-start+1==mid){
//                 maxi = c[dq.front()];

//                 long long check = maxi + mid*sum;

//                 if(check<=k)    return true;

//                 sum-=r[start];
//                 if(maxi==c[start]){
//                     dq.pop_front();
//                 }
//                 start++;
//             }  
//             end++;
//         }

//         return false;
//     }
//     int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
//         long long start = 1;
//         long long end = chargeTimes.size();
//         long long ans =0;
//         while(start<=end){
//             auto mid = start+(end-start)/2;
//             if(isFeasible(chargeTimes,runningCosts,budget,mid)){
//                 ans=mid;
//                 start=mid+1;
//             }else{
//                 end=mid-1;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    bool isValid(int k, vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        
        int i=0;
        int j=0;
        
        long long sum = 0;
        int maxi = 0;
        
        list<int> l;
        
        while(j<n) {
            // calculate sum of running costs till we hit the window size
            sum+=runningCosts[j];

            // to maintain maximum at the begining of the list
            while(l.size() > 0 and l.back() < chargeTimes[j]) l.pop_back();
            
            l.push_back(chargeTimes[j]);
            
            if(j-i+1 == k) {
                // when we hit the window size of k running robots
                
                maxi = l.front(); // maximum is at the front of the list
                
                long long b = maxi + k*sum;
                // Cost of running k consecutive robots
                // if in budget return true
                if(b <= budget) return true;

                // else shift the window by 1
                sum-=runningCosts[i];
                if(maxi == chargeTimes[i]) {
                    l.pop_front();
                }
                i++;
            }
            
            j++;
        }
        
        return false;
        
    }

    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int s = 1;
        int e = chargeTimes.size();
        
        int ans = 0;
        
        while(s<=e) {
            int k = s+(e-s)/2;
            
            if(isValid(k, chargeTimes, runningCosts, budget)) {
                ans = k;
                s=k+1;
            }
            else e = k-1;
        }
        
        return ans;
    }
};