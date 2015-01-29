class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len{0};
        for (int beg = 0; *s; ++s)
            if (*s == ' ') beg = 0;
            else len = ++beg;
        return len;
    }
};
