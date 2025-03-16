#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> charCount(26, 0);  // a~z 문자 개수를 저장할 배열 (고정 크기)

        // magazine의 문자 개수 카운트
        for (char m_c : magazine) {
            charCount[m_c - 'a']++;  // 'a'를 0번 인덱스로 매핑
        }

        // ransomNote의 문자 개수 확인
        for (char r_c : ransomNote) {
            if (charCount[r_c - 'a'] == 0) {
                return false;  // 필요한 문자가 부족하면 실패
            }
            charCount[r_c - 'a']--;  // 사용한 문자 줄이기
        }

        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;  // true/false 출력

    cout << sol.canConstruct("a", "b") << endl;       // false
    cout << sol.canConstruct("aa", "bb") << endl;     // false
    cout << sol.canConstruct("aa", "aab") << endl;    // true
    cout << sol.canConstruct("aa", "ab") << endl;     // false
}

