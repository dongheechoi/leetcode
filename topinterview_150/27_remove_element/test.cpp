// https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // remove all occurences of val in nums
        int k = 0;
        for (int i = 0 ; i < nums.size() ; i ++ ){
           if (nums[i] != val) {
               if ( nums[i] != nums[k]){
                   nums[k] = nums[i];
               }
               k++;
           };
        };
        return k;
    }
};

int main(){
    Solution s;
    // vector<int> nums = {3,2,2,3};
    // int val = 3;
    vector<int> nums = {3,2,2,3};
    int val = 3;

    int k = s.removeElement(nums, val);
    cout << "k: " << k << endl;
    for (int i = 0 ; i < nums.size(); i ++){
        cout << nums[i] << "/";
    };
    cout << "\n";
};
