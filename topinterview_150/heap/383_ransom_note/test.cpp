#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mCnt;
        for (int m_idx = 0 ; m_idx < magazine.size(); m_idx++){
            char m_c = magazine[m_idx];
            mCnt[m_c]++;
        }
        
        bool find = true;
        for (int r_idx = 0 ; r_idx < ransomNote.size() ; r_idx++ ){
            char r_c = ransomNote[r_idx];
            auto it = mCnt.find(r_c);
            if (it != mCnt.end()){
                if(it->second > 0){
                    it->second--;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        return find;
    }
};

int main(){

    Solution sol;
    int res;
    string ransomeNote;
    string magazine;
    
    ransomeNote = "a";
    magazine = "b";
    res = sol.canConstruct(ransomeNote, magazine);
    cout << "[Input] ransomeNote: " << ransomeNote << " / magazine: " << magazine << endl;
    cout << "\t[Predict] result: " << res << endl;
    cout << "\t[Answer ] result: false" << "\n"<< endl;

    ransomeNote = "aa";
    magazine = "bb";
    res = sol.canConstruct(ransomeNote, magazine);
    cout << "[Input] ransomeNote: " << ransomeNote << " / magazine: " << magazine << endl;
    cout << "\t[Predict] result: " << res << endl;
    cout << "\t[Answer ] result: false" << "\n"<< endl;

    ransomeNote = "aa";
    magazine = "aab";
    res = sol.canConstruct(ransomeNote, magazine);
    cout << "[Input] ransomeNote: " << ransomeNote << " / magazine: " << magazine << endl;
    cout << "\t[Predict] result: " << res << endl;
    cout << "\t[Answer ] result: true" << "\n"<< endl;

    ransomeNote = "aa";
    magazine = "ab";
    res = sol.canConstruct(ransomeNote, magazine);
    cout << "[Input] ransomeNote: " << ransomeNote << " / magazine: " << magazine << endl;
    cout << "\t[Predict] result: " << res << endl;
    cout << "\t[Answer ] result: false" << "\n"<< endl;
}
