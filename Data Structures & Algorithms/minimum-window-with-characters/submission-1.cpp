/*
invariance: in a particular window, all elements should hash to give more than t
obs1:
1. at any point of character, we have limited a-z and A-Z, so we can build a prefix sum
2. it can be reduced to find the substring, exactly equal to k, where k is a frequency arr
3. this is usually done using hash map

obs2:
1. left of a window can move, if we achieve required freq arr. we move until its good
2. what if we miss out something in complete which could later complete the invariance?
    - if we keep the right, to later get answer, it will not give smaller substring
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int tarr[256] = {0};
        int sarr[256] = {0};
        for (int i = 0; i < t.length(); i++) {
            tarr[t[i]]++;
        }
        int target = 0;
        for (int i = 0; i < 256; i++) {
            target += (tarr[i] != 0);
        }
        int match = 0;
        int r = 0;
        int start = 0;
        int minlen = s.length() + 1;
        for (int i = 0; i < s.length(); i++) {
            if (!tarr[s[i]])
                continue;
            if (r < i) r = i;
            while (r < s.length() && match < target) {
                if (tarr[s[r]]) {
                    if (++sarr[s[r]] == tarr[s[r]])
                        match++;
                }
                r++;
            }
            if (match == target) {
                if (minlen > r - i) {
                    minlen = r - i;
                    start = i;
                }
            }
            if (sarr[s[i]]-- == tarr[s[i]]) {
                if (r == s.length()) break;
                match--;
            }
        }
        if (start == 0 && minlen >= s.length() && match != target)
            return "";
        return s.substr(start, minlen);
    }
};
