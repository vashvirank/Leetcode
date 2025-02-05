// Leetcode 2116. Check if a Parentheses String Can Be Valid
// Author: Vashvi Rank
class Solution {
public:
    bool helper(string &s){
        stack<int>st;
        for (char &c : s) {
            if (c == '(') st.push(c);
            else {
                if (st.empty()) return false;
                char top = st.top();
                if (top == '(') st.pop(); 
                else return false; 
            }
        }
        return st.empty();
    }
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n & 1) return 0;
        if(helper(s)) return 1;
        int open, close;
        open = close = n/2;
        for(int i = 0; i < n; i++){
            if(locked[i] == '0') continue;
            if(s[i] == '(') open--;
            else close--;
        } 
        for(int i = 0; i < n; i++){
            if(locked[i] == '1') continue;
            if(open > 0){
                s[i] = '(';
                open--;
            }
            else{
                s[i] = ')';
                close--;
            }
        }
        if(helper(s)) return 1;
        return 0;
    }
};
