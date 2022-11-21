#include <cstdlib>
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        // max int 2147483647
        int max_digits[] = {2,1,4,7,4,8,3,6,4,7};
        int rev_x[10] = {};
        int orig_num = x;

        x = abs(x);
        int i = 0;

        // get number of digits
        int num_digit = 0;
        while (x > 0) {
            x /= 10;
            num_digit++;
        }

        bool max_num_digit = num_digit == 10;
        int total_digits = num_digit;
        bool is_same = true;
        x = abs(orig_num);

        while (num_digit > 0) {
            int digit = abs(x % 10);

            if (max_num_digit && is_same) {
                if (digit < max_digits[total_digits - num_digit]) {
                    is_same = false;
                }
                else if (digit > max_digits[total_digits - num_digit]) {
                    return 0;
                }
            }
            rev_x[num_digit - 1] = digit;

            // iterate
            x /= 10;
            num_digit--;
        }
        
        int final_rev_x = 0;
        for (int i = total_digits - 1; i >= 0; i--) {
            final_rev_x += pow(10, i) * rev_x[i];
        }
        if (orig_num < 0) {
            final_rev_x *= -1;
        }
        return final_rev_x;
    }
};