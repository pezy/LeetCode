class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (!*haystack && !*needle) return 0;
        char *p = haystack;
        while (*p) {
            char *p1 = p, *p2 = needle;
            while (*p1 && *p2 && *p1 == *p2) {
                ++p1;
                ++p2;
            }
            if (!*p2) return p-haystack;
            else if (!*p1) break;
            ++p;
        }
        return -1;
    }
};
