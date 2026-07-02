#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution{
public:
    vector<int>dailyTemperatures(vector<int> &temperatures){
        int n = temperatures.size();
        vector<int>res(n);
        stack<int>st;
        for(int i = 0;i<n;i++){
            while( !st.empty() && temperatures[i] > temperatures[st.top()]){
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            
        }
        return res;
    }
};