#include<iostream>
#include<vector>
#include<set>
#include<limits.h>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // nums is a sorted array
        int w_idx = 0; // write index
        //int c_num = -1;
        int c_num = INT_MIN;
        for (int i = 0 ; i < nums.size(); i ++){
            if(c_num == nums[i]){
                continue;
            }
            else{
                cout << "c_num: " << c_num << " /write idx: " << w_idx  << endl;
                for (int i = 0 ; i < nums.size(); i ++){
                    cout << nums[i] << "/";
                };
                cout << "\n";

                nums[w_idx] = nums[i];
                w_idx++;
                c_num = nums[i];
            };
        };
        return w_idx ;
    }
};


int main(){
    Solution s;
    vector<int> nums = {1,1,2};
    int non_dup_res = s.removeDuplicates(nums);
    cout << "Number of Non duplicated entities: " << non_dup_res << endl;

    for (int i = 0 ; i < nums.size(); i ++){
        cout << nums[i] << "/";
    };
    cout << "\n";
};

