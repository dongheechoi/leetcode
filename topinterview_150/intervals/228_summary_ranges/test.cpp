#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // nums -> sorted unique integer array
        // return the smallest sorted list that cover all the numbers in the array exactly.

        vector<string> res;
        int start_idx = 0;
        int start_num;
        string flush_str;
        int idx;
        if(nums.size() == 0){
            return res;
        }
        if(nums.size() == 1){
            res.push_back(to_string(nums[0]));
            return res;
        }

        for(idx = 1 ; idx < nums.size() ; idx++ ){
            //cout << "idx: " << idx  
            //    << "/start_idx: " << start_idx 
            //    << "/start_idx_val: " << nums[start_idx]
            //    << endl;

            // cout << "\tcompare [before]:" << nums[idx -1] << "/[after]:" << nums[idx] << endl; 
            //if ((nums[idx - 1] - nums[idx]) == -1){
            //    // incremental
            //    cout << "\tincremental" << endl;
            //}
            //else{
            if ((nums[idx - 1] + 1) != nums[idx]){
                //Input is a sorted unqiue list, no need to think about other cases
                if(nums[start_idx] == nums[idx-1]){
                    flush_str = to_string(nums[start_idx]);
                }else{
                    flush_str = to_string(nums[start_idx]) + "->" + to_string(nums[idx-1]);
                }
                //cout << "\tnot incremental: "<< flush_str << endl;
                res.push_back(flush_str);
                start_idx = idx;
            }
        }
        if(nums[start_idx] == nums[idx-1]){
            flush_str = to_string(nums[start_idx]);
        }else{
            flush_str = to_string(nums[start_idx]) + "->" + to_string(nums[nums.size()-1]);
        }
        res.push_back(flush_str);
        
        return res;
    }
};


void exp(Solution& sol, vector<int>& nums){
    vector<string> res = sol.summaryRanges(nums);
    cout << "Input: " ;
    for(int input_idx = 0 ; input_idx < nums.size() ; input_idx++){
        cout << nums[input_idx] << "/";
    }
    cout << "\nOutput: ";
    for (int res_idx = 0 ; res_idx < res.size(); res_idx++){
        cout << res[res_idx] << "/";
    }
    cout << "\n";
}

int main(){
    
    Solution sol;
    vector<int> nums;
    
    cout << "Exp1" <<endl;
    nums = {0,1,2,4,5,7};
    exp(sol, nums);

    cout << "==============" <<endl;
    cout << "Exp2" <<endl;
    nums = {0};
    exp(sol, nums);

    cout << "==============" <<endl;
    cout << "Exp3" <<endl;
    nums = {0,1};
    exp(sol, nums);

    cout << "==============" <<endl;
    cout << "Exp4 - error case from leetcode" <<endl;
    nums = {-2147483648,-2147483647,2147483647};
    exp(sol, nums);
    //vector<string> res;
    //int input_idx;
    //int res_idx;

}
