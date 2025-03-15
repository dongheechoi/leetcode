#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // target: positive integer
        // nums : positive integers
        // return the minimal length of a subarray
        // whose sum is greater than or equal to target.

        vector<int> cache(nums.size(), 0);
        for (int idx1 = 0 ; idx1 < nums.size() ; idx1 ++ ){
            if (nums[idx1] >= target){
                return 1; // w_size = 1
            }
            cache[idx1] = nums[idx1]; // maybe better way? like initialization?
        }

        for(int w_size = 2; w_size < nums.size() + 1 ; w_size ++ ){
            // cout << "window size: " << w_size << endl;
            // if find -> return w_size

            for (int i = 0 ; i < nums.size() - w_size + 1 ; i ++ ){
                int sum = 0;
                //for (int c_idx = 0 ; c_idx < cache.size() ; c_idx ++){
                //    cout  << cache[c_idx] << ",";
                //}
                // cout << "\n";
                sum = cache[i] + nums[i + w_size - 1];
                //cout << "i: " << i << "/ cache[i]=" << cache[i] << "/ idx = " << i + w_size - 1 << "/ nums[idx] = "<< nums[i + w_size -1 ]<< "/ sum: "<< sum << endl;
                if (sum >= target){
                    //cout <<"\nReturn" <<endl;
                    return w_size;
                }
                cache[i] = sum;
                // cout << "\n";
            }
        }
        
        return 0;
    }
};

int main(){
    Solution sol;

    //int target = 7; // positive integer
    //vector<int> nums = {2,3,1,2,4,3}; // positive integers

    int target = 15; // positive integer
    vector<int> nums = {1,2,3,4,5}; // positive integers
    int res = sol.minSubArrayLen(target, nums);
    cout << res << endl;
}

