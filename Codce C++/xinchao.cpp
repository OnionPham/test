#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution{
public:
    vector<int>dailyTemperatures(vector<int> &temperatures){
        int n = temperatures.size();
        vector<int>res(n);
        for(int i = 0;i<n;i++){
            int j = i + 1;
            while(j < n && temperatures[j] <= temperatures[i])j++;
            res[i] = (j < n) ? j - i : 0;
        }
        return res;
    }
};
int main(){
    vector<int>temps = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution sol;
    vector<int>result = sol.dailyTemperatures(temps);
    for(int x : result) cout << x << " ";
    return 0;
}