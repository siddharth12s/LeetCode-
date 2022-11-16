/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int end = n;
        int start=1;
        
        while(start<end){
            int m = (start + (end-start)/2);
            
            if(guess(m)==-1){
                end=m-1;
            }
            else if(guess(m)==1){
                start=m+1;
            }else{
                return m;
            }
        }
        return end;
    }
};