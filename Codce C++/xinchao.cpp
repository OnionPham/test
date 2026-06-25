#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution{
public:
   int removeDuplicates(vector<int>&nums){
        string res;
        int i = 0,j=1;
        while(i < nums.size() && j < nums.size()){
            if(nums[i] == nums[j]){
                j++;
            }
            else{
                res.push_back(nums[i]);
                i = j;
                j++;
            }
        }
        return res.size();
   }
};
int main(){
    vector<int>nums;
    for(auto &x : nums)cin >> x;
    Solution sol;
    cout << sol.removeDuplicates(nums);
}