class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff(0), a(-1), b(-1);
        for(int i = 0; i < s1.size(); i++) 
        {
            if(s1[i] != s2[i]){
                diff++;
                if(a == -1) a = i;
                else if(b == -1) b = i;
            }
        }
        if(diff == 0) return 1;
        return (diff == 2 && s1[a] == s2[b] && s1[b] == s2[a] ? 1 : 0);
    }
};
