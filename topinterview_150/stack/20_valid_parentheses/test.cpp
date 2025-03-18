#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int s_idx = 0 ; s_idx < s.size() ; s_idx ++){
            if((s[s_idx] == '(') || (s[s_idx] == '{') || (s[s_idx] == '[')){
                // cout << "\tpush: " << s[s_idx] << endl;
                st.push(s[s_idx]);
            }else{ // s consists of parentheses only ()[]{}
                if(st.size() == 0){
                    return false;
                }else if ( (st.top() == '(') && (s[s_idx] == ')') | 
                    (st.top() == '[') && (s[s_idx] == ']') | 
                    (st.top() == '{') && (s[s_idx] == '}') ){
                    // cout << "\tnot right: st.top(): '" << st.top() 
                    // << "' / s[s_idx]: '" << s[s_idx] << "'" 
                    // << st.top() -  s[s_idx]<< endl;
                    // cout << "\tpop :" << st.top() << endl;
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.size() > 0){
            return false;
        }

        return true;
    }
};

int main(){
    Solution sol;
    string s;
    bool res;

    // cout << "(" - ")" << endl;
    // cout << "[" - "]" << endl;
    // cout << "{" - "}" << endl;

    s = "()";
    res = sol.isValid(s);
    cout << "Input: " << s << endl;
    cout << "Res  : " << res << endl;

    s = "()[]{}";
    res = sol.isValid(s);
    cout << "Input: " << s << endl;
    cout << "Res  : " << res << endl;

    s = "(]";
    res = sol.isValid(s);
    cout << "Input: " << s << endl;
    cout << "Res  : " << res << endl;

    s = "([])";
    res = sol.isValid(s);
    cout << "Input: " << s << endl;
    cout << "Res  : " << res << endl;

    s = "]";
    res = sol.isValid(s);
    cout << "Input: " << s << endl;
    cout << "Res  : " << res << endl;
    return 0;
}
