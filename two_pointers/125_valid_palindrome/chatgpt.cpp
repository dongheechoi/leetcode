#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int f_idx = 0, b_idx = s.size() - 1;

        while (f_idx < b_idx) {
            // 앞에서부터 유효한 문자 찾기
            while (f_idx < b_idx && !isalnum(s[f_idx])) f_idx++;
            // 뒤에서부터 유효한 문자 찾기
            while (f_idx < b_idx && !isalnum(s[b_idx])) b_idx--;

            // 팰린드롬 체크 (대소문자 무시)
            if (tolower(s[f_idx]) != tolower(s[b_idx])) return false;

            f_idx++; b_idx--;
        }

        return true;
    }
};

int main(){
    Solution sol;
    string s = "s";
    bool res = sol.isPalindrome(s);
    cout << "Input: "<<s << "// Res: " << res << endl;

    s = "";
    res = sol.isPalindrome(s);
    cout << "Input: "<<s << "// Res: " << res << endl;

    s = "abc";
    res = sol.isPalindrome(s);
    cout << "Input: "<<s << "// Res: " << res << endl;

    s = "A man, a plan, a canal: Panama";
    res = sol.isPalindrome(s);
    cout << "Input: "<<s << "// Res: " << res << endl;

    s = "0P";
    res = sol.isPalindrome(s);
    cout << "Input: "<<s << "// Res: " << res << endl;
    //cout << 'A' - 'a' << endl;
    //cout << (int)'A' << endl;
    //cout << (int)'Z' << endl;
    //cout << (int)'a' << endl;
    //cout << (int)'z' << endl;
    //cout << char('A' + 32) << endl;
    //cout << char('B' + 32) << endl;
    //cout << char('Z' + 32) << endl;
    //cout << char(91) << endl;
    //cout << char(92) << endl;
}
