#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int convertAvailChar(char c){
        // 'a': 97, 'z': 122, 'A': 65, 'Z': 90, Upper + 32 = Lower
        if (((int)c >=48 && (int)c <= 57) || ((int)c >= 97 && (int)c <= 122)) {
            return (int)c;
        };
        if ((int)c >= 65 && (int)c <= 90){
            return (int)c + 32;
        };
        return -1;
    }

    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1){
            // cout << "Earlystopping: " << s.size() << endl;
            return true;
        }
        int f_idx = 0;
        int b_idx = s.size() - 1;
        // cout << "[Inital] f_idx: " << f_idx << " / b_idx: " << b_idx << endl;

        //for (int i = 0 ; i < s.size(); i ++){
        //    cout<< "["<< s[i] << "/" << convertAvailChar(s[i]) << "]";
        //}
        // cout << "\n";
        while (f_idx < b_idx){
            //cout << "f_idx: " << f_idx << " / b_idx: " << b_idx << endl;

            int f_char_num = -1;
            int b_char_num = -1;
            while(f_char_num == -1 && f_idx < s.size()){
                f_char_num = convertAvailChar(s[f_idx]);
                f_idx ++;
            }

            while(b_char_num == -1 && b_idx >= 0){
                b_char_num = convertAvailChar(s[b_idx]);
                b_idx --;
            }
            if(f_char_num != b_char_num){
                return false;
            }
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
