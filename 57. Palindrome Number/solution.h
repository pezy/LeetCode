class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long rev{0}, origin{x};
        do {
            rev = rev * 10 + x % 10;
        } while (x /= 10);
        return rev == origin;
    }
};
