#include <iostream>
#include <string>

class Solution {
   public:
    bool validPalindrome(std::string s) {
        int len = s.size();

        if (len == 3) {
            if (s[0] == s[2]) {
                return true;
            }

            return false;
        }

        bool isPalindrome = true;
        int8_t n = 1;
        for (int i = 0; i < int(len / 2); i++) {
            if (s[i] == s[len - n - i]) {
                continue;
            } else if (n == 1) {
                n = 2;
                if (s[i] == s[len - n - i]) {
                    continue;
                }

                n = 0;
                i++;
                if (s[i] == s[len - n - i]) {
                    continue;
                }
            }
            isPalindrome = false;
            break;
        }

        if (isPalindrome) {
            return isPalindrome;
        }

        isPalindrome = true;
        n = 1;
        for (int i = 0; i < int(len / 2); i++) {
            if (s[i] == s[len - n - i]) {
                continue;
            } else if (n == 1) {
                n = 0;
                i++;
                if (s[i] == s[len - n - i]) {
                    continue;
                }

                n = 2;
                i--;
                if (s[i] == s[len - n - i]) {
                    continue;
                }
            }
            isPalindrome = false;
            break;
        }

        return isPalindrome;
    }
};