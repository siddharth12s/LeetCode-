class Solution {
public:
    bool isFeasible(vector<int> &c, vector<int> &r, long long k, long long mid) {
        long long sum = 0;
        long long start = 0, end = 0;
        deque<int> dq;
        long long maxi = (long long)c[0];

        while(end<c.size()){
            sum += r[end];

            while(!dq.empty() and c[dq.back()]<=c[end]){
                dq.pop_back();
            }
            dq.push_back(end);

            if(end-start+1>mid){
            }

            if(end-start+1==mid){
                maxi = c[dq.front()];
                long long check = maxi + mid*sum;

                if(check<=k)
                    return true;

                sum-=r[start];
                if(maxi==c[start]){
                    dq.pop_front();
                }
                start++;
            }
            end++;
        }

        return false;        
    }

    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int start = 1;
        int end = chargeTimes.size();
        int ans = 0;

        // Binary search over the number of robots (window size)
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isFeasible(chargeTimes, runningCosts, budget, mid)) {
                ans = mid; // If feasible, update answer
                start = mid + 1; // Try a larger window size
            } else {
                end = mid - 1; // Try a smaller window size
            }
        }

        return ans; // Return the maximum number of robots that can run within the budget
    }
};
