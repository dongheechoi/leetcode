#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2){
            return nums.size();
        }
        // We don't have to check the first end second element.
        int w_idx = 2;
        
        /*
        for (int i1 = 0 ; i1 < nums.size(); i1 ++){
            cout << nums[i1] << "/";
        };
        cout << "\n";
        */

        for (int i = 2 ; i < nums.size(); i++){
            /*
            cout << "[con] i:" << i << "/ w_idx: " << w_idx << endl;
            for (int i2 = 0 ; i2 < nums.size(); i2 ++){
                if (i2 == w_idx){
                    cout << "_";
                };
                if (i == i2){
                    cout << "[" << nums[i2] <<"]";
                }else{
                    cout << nums[i2] ;
                };
                if (i2 == w_idx){
                    cout << "_";
                };
                cout << "/";
            };
            cout << "\n";
            */
            if(nums[i] == nums[w_idx-1] && nums[i] == nums[w_idx-2] ){
                // cout <<"\t/ nums[i]:"<< nums[i] << "/ nums[w_idx]:"<<nums[w_idx] << "/ nums[w_idx-1]:"<< nums[w_idx-1] << endl;
                continue;
            }else{
                nums[w_idx] = nums[i];
                w_idx ++;
            };
            
        }
        return w_idx; 
    }
};

int main(){
    Solution s;

    vector<int> nums = {1,1,1,2,2,3};
    int res = s.removeDuplicates(nums);
    cout << "Res num: " << res << endl;
    for (int i = 0 ; i < nums.size(); i ++){
        cout << nums[i] << "/";
    };
    cout << "\n";
};
