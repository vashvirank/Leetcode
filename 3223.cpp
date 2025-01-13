//3223. Minimum Length of String After Operations
// Author: Vashvi Rank
class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<char, int>m;
        for(char &h : s) m[h]++;
        for(auto &h : m)
            if(h.second > 2)   
                n -= (h.second - (h.second & 1 ? 1 : 2));
        return n;
    }
};
