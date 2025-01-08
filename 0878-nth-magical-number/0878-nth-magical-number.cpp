class Solution {
public:
    int mod = 1e9 + 7;

    long long int is_feasible(long long int mid, int n,int a, int b){
        long long int gc = gcd(a,b);
        long long int lcm = a*b/gc;
        long long int check = mid/a + mid/b - mid/lcm;

        return check;
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long int mini = min(a,b);
        long long int maxi = max(a,b);

        long long int max_range = mini*n;
        

        long long start = mini,end=max_range;

        while(start<end){
            long long mid = start + (end-start)/2;
            
            cout<<is_feasible(mid,n,a,b)<<endl;
            if(is_feasible(mid,n,a,b)<n){
                start=mid+1;
            }else{
                end=mid;
            }

        }

        return start%mod;
    }
};