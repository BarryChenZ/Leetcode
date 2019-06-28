class Solution {
public:
    int strStr(string haystack, string needle) {
        const char * a = haystack.c_str();
        const char * b = needle.c_str();
        const char *loc = strstr(a, b);
        if(loc == NULL) {
            return -1;
        }
        else {
            return loc-a;
        }
    }
};
