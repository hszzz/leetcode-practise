/**
 * Given an integer x, return true if x is palindrome integer.
 * An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
*/

// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        bool ret = false;
        
        if (x >= 0) {
            long long int reverse = 0;
            int num = x;
            while (x) {
                reverse = reverse*10 + x%10; 
                x /= 10;
            }
            ret = reverse == num ? true : false;
        } else {
            ret = false;
        }
        
        return ret;
    }
};