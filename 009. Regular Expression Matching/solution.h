class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        for (char c=*p; c != '\0'; ++s, c=*p) {
            if (p[1] != '*') ++p;
            else if (isMatch(s, p+2)) return true;
            if (!(c == *s || (c == '.' && *s != '\0'))) return false;
        }
        return *s == '\0';
    }
};
