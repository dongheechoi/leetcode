#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;  // 시간 측정용

// ✅ 비교 연산 있음
int removeElement1(vector<int>& nums, int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            if (nums[i] != nums[k]) {  // <-- 비교 연산
                nums[k] = nums[i];
            }
            k++;
        }
    }
    return k;
}

// ✅ 비교 연산 없음 (바로 복사)
int removeElement2(vector<int>& nums, int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k++] = nums[i];  // <-- 비교 없이 바로 복사
        }
    }
    return k;
}

// ✅ 실행 시간 측정 함수
void benchmark(int (*func)(vector<int>&, int), vector<int> nums, int val, const string& name) {
    auto start = high_resolution_clock::now();  // 시작 시간
    func(nums, val);
    auto end = high_resolution_clock::now();    // 끝난 시간
    double duration = duration_cast<microseconds>(end - start).count();
    cout << name << " 실행 시간: " << duration << "μs" << endl;
}

int main() {
    int N = 1000000;  // 테스트 데이터 크기
    vector<int> nums(N, 1);
    nums[N / 2] = 2;   // 제거할 값 일부 넣기
    int val = 2;

    cout << "=== 벤치마크 시작 ===" << endl;
    benchmark(removeElement1, nums, val, "removeElement1 (비교 연산 있음)");
    benchmark(removeElement2, nums, val, "removeElement2 (비교 연산 없음)");
    cout << "=== 벤치마크 종료 ===" << endl;

    return 0;
}
