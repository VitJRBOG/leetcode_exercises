#include <iostream>

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int64_t palindrome = 0;
        auto orig = x;

        while (true) {
            if (palindrome > 0) {
                palindrome = palindrome * 10;
            }

            palindrome += x % 10;
            x /= 10;

            if (x == 0) {
                break;
            }
        }

        if (palindrome == orig) {
            return true;
        }

        return false;
    }
};