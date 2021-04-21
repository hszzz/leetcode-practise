/**
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

https://leetcode.com/problems/valid-parentheses/
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i<s.length(); i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            
            if (s[i] == ')' && st.top() == '(')
                st.pop();
            else if (s[i] == ']' && st.top() == '[')
                st.pop();
            else if (s[i] == '}' && st.top() == '{')
                st.pop();
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};
