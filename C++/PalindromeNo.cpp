#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // If x is negative or ends in a zero but is not 0, it cannot be a palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        // If x has odd number of digits, we need to divide reversed by 10 to exclude the middle digit
        return x == reversed || x == reversed / 10;
    }
};
