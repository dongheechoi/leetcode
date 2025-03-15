// https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){

        vector<int> buffer = {};
        // int m_idx = nums1.size() - 1;
        int idx1 = m - 1;
        int idx2 = n - 1;
        int m_idx = nums1.size() -1 ;

        while (m_idx >= 0){
            if (idx2 < 0 ){
                break;
            };
            // idx1 for loop over nums1
            if (idx1 >= 0 && nums1[idx1] >= nums2[idx2]){
                // continue moving until find something
                nums1[m_idx] = nums1[idx1];
                idx1--;
            }
            else{
                nums1[m_idx] = nums2[idx2];
                idx2--;
            };
            m_idx--;
            // nums1[0] 
            
            cout << "idx1: " << idx1 << " / idx2: " << idx2 << endl;
            for(int idx = 0 ; idx < nums1.size() ; idx++ ){
                cout << nums1[idx] << "/";
            };
            cout << "\n";
        };
        // cout << "[Out of for loop]" << endl;
        // cout << "idx1: " << idx1 << " / idx2: " << idx2 << endl;
        while (idx2 >= 0){
            nums1[idx2] = nums2[idx2];
            idx2 --;
        };
    }
};

int main(){
    Solution s;
    // vector nums1 = {1,2,3,0,0,0};
    // int m = 3;
    // vector nums2 = {2,5,6};
    // int n = 3;

    //vector nums1 = {0};
    //int m = 0;
    //vector nums2 = {1};
    //int n = 1;

    // vector nums1 = {1,2,3,0,0,0};
    // int m = 3;
    // vector nums2 = {4,5,6};
    // int n = 3;
    vector nums1 = {4,5,6,0,0,0};
    int m = 3;
    vector nums2 = {1,2,3};
    int n = 3;
    s.merge(nums1, m, nums2, n);
    cout << "// Final Result //" << endl;
    for(int idx = 0 ; idx < nums1.size() ; idx++ ){
        cout << nums1[idx] << "/";
    }; 
}
