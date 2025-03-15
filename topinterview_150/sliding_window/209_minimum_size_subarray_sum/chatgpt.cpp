#include <iostream>
#include <vector>
#include <limits.h> // INT_MAX 사용

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, min_len = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];  // 윈도우에 새로운 값 추가
            
            // sum이 target 이상이면, 최소 길이 갱신 & 윈도우 축소
            while (sum >= target) {
                min_len = min(min_len, right - left + 1);
                sum -= nums[left];  // 왼쪽 요소 빼기 (윈도우 축소)
                left++;  // 윈도우 왼쪽 이동
            }
        }

        return (min_len == INT_MAX) ? 0 : min_len;
    }
};

int main() {
    Solution sol;

    int target = 15;
    vector<int> nums = {1, 2, 3, 4, 5};
    
    int res = sol.minSubArrayLen(target, nums);
    cout << res << endl;  // 결과 출력
}
